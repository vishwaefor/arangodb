#!/bin/sh

# os detection
ar_detect_os(){
    local file="/etc/centos-release"
    local os="unknown release"
    if [ -f "$file" ]; then
        os="centos"
        if grep -q -s " 6" "$file" &>/dev/null ; then
            os+="6"
        elif grep -q -s " 7" "$file" &>/dev/null ; then
            os+="7"
        fi
    fi
    echo "$os"

    #debian
    #opensuse
    #mac
}
#export detected os
export ARANGO_OS="$(ar_detect_os)"


#print error message
ar_err(){
    local msg="$1"
    echo "ERROR: $msg" &>2
}

#print fatal error message and exit
ar_ferr(){
    local msg="$1"
    local code="${2-1}"
    echo "FATAL ERROR: $msg" &>2
    exit "$code"
}

## exit codes and other data

#function for searching .dat files
ar_find_dat_file(){
    local name="$1"
    local found=false
    for p in "/usr/share/arangodb3" "some other path"; do
        local full_path="$p/$name"
        if [ -f "$full_path" ]; then
            found=true
            echo "$full_path"
            break
        fi
    done

    if ! $found; then
        echo "$could not find datafile $name"
    fi
}

export ARANGO_ERROR_CODES_DAT="$(ar_find_dat_file exitcodes.dat)"

ar_exitcode_num_to_string(){
    in="$1"
    local found=false
    if [ -f $file ]; then
        while IFS=',' read code num _ ; do
            if [ "$in" == "$num" ]; then
                echo $code
                found=true
                break
            fi
        done < "$file"
    else
        echo "EXIT_CODE_RESOLVING_FAILED for code $in"
    fi

    if ! $found; then
        echo "EXIT_CODE_RESOLVING_FAILED for code $in"
    fi
}

ar_exitcode_num_to_message(){
    local in="$1"
    if [[ $in == "0" ]]; then
        return
    fi
    local file="$ARANGO_ERROR_CODES_DAT"
    local found=false
    if [ -f $file ]; then
        while IFS=',' read code num message long_message; do
            if [ "$in" == "$num" ]; then
                echo "EXIT($1) - $message"
                found=true
                break
            fi
        done < "$file"
    else
        echo "EXIT($in) - could not resolve error message"
    fi

    if ! $found; then
        echo "EXIT($in) - could not resolve error message"
    fi
}

ar_exitcode_string_to_num(){
    local file="$ARANGO_ERROR_CODES_DAT"
    local found=false
    if [ -f $file ]; then
        in="$1"
        while IFS=',' read code num _ ; do
            if [ "$in" == "$code" ]; then
                echo $num
                found=true
                break
            fi
        done < "$file"
    else
        echo 2
    fi

    if ! $found; then
        echo 2
    fi
}

ar_exit_by_num(){
    local code="$1"
    local msg="$(ar_exitcode_num_to_string $code)"
    if [ $code -ne 0 ]; then
        echo "FATAL ERROR: $msg" &>2
        exit "$code"
    fi
}

ar_exit_by_string(){
    local code=$(ar_exitcode_string_to_num "$1")
    ar_exit_by_num $code
}

