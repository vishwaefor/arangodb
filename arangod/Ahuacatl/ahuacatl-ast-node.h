////////////////////////////////////////////////////////////////////////////////
/// @brief Ahuacatl, parser nodes
///
/// @file
///
/// DISCLAIMER
///
/// Copyright 2014 ArangoDB GmbH, Cologne, Germany
/// Copyright 2004-2014 triAGENS GmbH, Cologne, Germany
///
/// Licensed under the Apache License, Version 2.0 (the "License");
/// you may not use this file except in compliance with the License.
/// You may obtain a copy of the License at
///
///     http://www.apache.org/licenses/LICENSE-2.0
///
/// Unless required by applicable law or agreed to in writing, software
/// distributed under the License is distributed on an "AS IS" BASIS,
/// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
/// See the License for the specific language governing permissions and
/// limitations under the License.
///
/// Copyright holder is ArangoDB GmbH, Cologne, Germany
///
/// @author Jan Steemann
/// @author Copyright 2014, ArangoDB GmbH, Cologne, Germany
/// @author Copyright 2012-2013, triAGENS GmbH, Cologne, Germany
////////////////////////////////////////////////////////////////////////////////

#ifndef ARANGODB_AHUACATL_AHUACATL__AST__NODE_H
#define ARANGODB_AHUACATL_AHUACATL__AST__NODE_H 1

#include "Basics/Common.h"

#include "Ahuacatl/ahuacatl-node.h"

struct TRI_aql_context_s;

// -----------------------------------------------------------------------------
// --SECTION--                                                  public functions
// -----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST nop node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeNopAql (void);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST return node with an empty list as argument
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeReturnEmptyAql (void);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST scope start node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeScopeStartAql (struct TRI_aql_context_s* const, void*);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST scope end node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeScopeEndAql (struct TRI_aql_context_s* const, void*);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST for node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeForAql (struct TRI_aql_context_s* const,
                                      const char* const,
                                      const TRI_aql_node_t* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST let node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeLetAql (struct TRI_aql_context_s* const,
                                      const char* const,
                                      const TRI_aql_node_t* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST filter node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeFilterAql (struct TRI_aql_context_s* const,
                                         const TRI_aql_node_t* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST return node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeReturnAql (struct TRI_aql_context_s* const,
                                         const TRI_aql_node_t* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST remove node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeRemoveAql (struct TRI_aql_context_s* const,
                                         const TRI_aql_node_t* const,
                                         const TRI_aql_node_t* const,
                                         TRI_aql_node_t*);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST insert node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeInsertAql (struct TRI_aql_context_s* const,
                                         const TRI_aql_node_t* const,
                                         const TRI_aql_node_t* const,
                                         TRI_aql_node_t*);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST update node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeUpdateAql (struct TRI_aql_context_s* const,
                                         const TRI_aql_node_t* const,
                                         const TRI_aql_node_t* const,
                                         const TRI_aql_node_t* const,
                                         TRI_aql_node_t*);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST replace node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeReplaceAql (struct TRI_aql_context_s* const,
                                          const TRI_aql_node_t* const,
                                          const TRI_aql_node_t* const,
                                          const TRI_aql_node_t* const,
                                          TRI_aql_node_t*);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST collect node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeCollectAql (struct TRI_aql_context_s* const,
                                          const TRI_aql_node_t* const list,
                                          const char* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST sort node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeSortAql (struct TRI_aql_context_s* const,
                                       const TRI_aql_node_t* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST sort element node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeSortElementAql (struct TRI_aql_context_s* const,
                                              const TRI_aql_node_t* const,
                                              const bool);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST limit node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeLimitAql (struct TRI_aql_context_s* const,
                                        const TRI_aql_node_t* const,
                                        const TRI_aql_node_t* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST assign node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeAssignAql (struct TRI_aql_context_s* const,
                                         const char* const,
                                         const TRI_aql_node_t* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST parameter node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeParameterAql (struct TRI_aql_context_s* const,
                                            const char* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST variable node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeVariableAql (struct TRI_aql_context_s* const,
                                           const char* const,
                                           TRI_aql_node_t* const,
                                           bool);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST collection node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeCollectionAql (struct TRI_aql_context_s* const,
                                             const char* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST reference node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeReferenceAql (struct TRI_aql_context_s* const,
                                            const char* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST unary plus node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeOperatorUnaryPlusAql (struct TRI_aql_context_s* const,
                                                    const TRI_aql_node_t* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST unary minus node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeOperatorUnaryMinusAql (struct TRI_aql_context_s* const,
                                                     const TRI_aql_node_t* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST unary not node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeOperatorUnaryNotAql (struct TRI_aql_context_s* const,
                                                   const TRI_aql_node_t* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST binary and node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeOperatorBinaryAndAql (struct TRI_aql_context_s* const,
                                                    const TRI_aql_node_t* const,
                                                    const TRI_aql_node_t* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST binary or node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeOperatorBinaryOrAql (struct TRI_aql_context_s* const,
                                                   const TRI_aql_node_t* const,
                                                   const TRI_aql_node_t* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST binary plus node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeOperatorBinaryPlusAql (struct TRI_aql_context_s* const,
                                                     const TRI_aql_node_t* const,
                                                     const TRI_aql_node_t* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST binary minus node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeOperatorBinaryMinusAql (struct TRI_aql_context_s* const,
                                                      const TRI_aql_node_t* const,
                                                      const TRI_aql_node_t* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST binary times node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeOperatorBinaryTimesAql (struct TRI_aql_context_s* const,
                                                      const TRI_aql_node_t* const,
                                                      const TRI_aql_node_t* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST binary div node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeOperatorBinaryDivAql (struct TRI_aql_context_s* const,
                                                    const TRI_aql_node_t* const,
                                                    const TRI_aql_node_t* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST binary mod node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeOperatorBinaryModAql (struct TRI_aql_context_s* const,
                                                    const TRI_aql_node_t* const,
                                                    const TRI_aql_node_t* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST binary eq node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeOperatorBinaryEqAql (struct TRI_aql_context_s* const,
                                                   const TRI_aql_node_t* const,
                                                   const TRI_aql_node_t* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST binary ne node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeOperatorBinaryNeAql (struct TRI_aql_context_s* const,
                                                   const TRI_aql_node_t* const,
                                                   const TRI_aql_node_t* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST binary lt node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeOperatorBinaryLtAql (struct TRI_aql_context_s* const,
                                                   const TRI_aql_node_t* const,
                                                   const TRI_aql_node_t* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST binary le node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeOperatorBinaryLeAql (struct TRI_aql_context_s* const,
                                                   const TRI_aql_node_t* const,
                                                   const TRI_aql_node_t* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST binary gt node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeOperatorBinaryGtAql (struct TRI_aql_context_s* const,
                                                   const TRI_aql_node_t* const,
                                                   const TRI_aql_node_t* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST binary ge node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeOperatorBinaryGeAql (struct TRI_aql_context_s* const,
                                                   const TRI_aql_node_t* const,
                                                   const TRI_aql_node_t* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST binary in node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeOperatorBinaryInAql (struct TRI_aql_context_s* const,
                                                   const TRI_aql_node_t* const,
                                                   const TRI_aql_node_t* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST ternary operator node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeOperatorTernaryAql (struct TRI_aql_context_s* const,
                                                  const TRI_aql_node_t* const,
                                                  const TRI_aql_node_t* const,
                                                  const TRI_aql_node_t* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST subquery node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeSubqueryAql (struct TRI_aql_context_s* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST attribute node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeAttributeAccessAql (struct TRI_aql_context_s* const,
                                                  const TRI_aql_node_t* const,
                                                  const char* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST attribute node w/ bind parameter
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeBoundAttributeAccessAql (struct TRI_aql_context_s* const,
                                                       const TRI_aql_node_t* const,
                                                       const TRI_aql_node_t* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST index access node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeIndexedAql (struct TRI_aql_context_s* const,
                                          const TRI_aql_node_t* const,
                                          const TRI_aql_node_t* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST expand node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeExpandAql (struct TRI_aql_context_s* const,
                                         const char* const,
                                         const TRI_aql_node_t* const,
                                         const TRI_aql_node_t* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST null value node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeValueNullAql (struct TRI_aql_context_s* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST int value node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeValueIntAql (struct TRI_aql_context_s* const,
                                           const int64_t);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST double value node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeValueDoubleAql (struct TRI_aql_context_s* const,
                                              const double);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST bool value node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeValueBoolAql (struct TRI_aql_context_s* const,
                                            const bool);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST string value node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeValueStringAql (struct TRI_aql_context_s* const,
                                              const char* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST list node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeListAql (struct TRI_aql_context_s* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST array node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeArrayAql (struct TRI_aql_context_s* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST function call node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeFcallAql (struct TRI_aql_context_s* const,
                                        const char* const,
                                        const TRI_aql_node_t* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief create an AST array element node
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_t* TRI_CreateNodeArrayElementAql (struct TRI_aql_context_s* const,
                                               const char* const,
                                               const TRI_aql_node_t* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief add a value to the end of a list
////////////////////////////////////////////////////////////////////////////////

bool TRI_PushListAql (struct TRI_aql_context_s* const,
                      const TRI_aql_node_t* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief add a value to the end of an array
////////////////////////////////////////////////////////////////////////////////

bool TRI_PushArrayAql (struct TRI_aql_context_s* const,
                       const char* const,
                       const TRI_aql_node_t* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief get the numeric value of a node
////////////////////////////////////////////////////////////////////////////////

double TRI_GetNumericNodeValueAql (const TRI_aql_node_t* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief get the boolean value of a node
////////////////////////////////////////////////////////////////////////////////

bool TRI_GetBooleanNodeValueAql (const TRI_aql_node_t* const);

////////////////////////////////////////////////////////////////////////////////
/// @brief reverse a relational operator
////////////////////////////////////////////////////////////////////////////////

TRI_aql_node_type_e TRI_ReverseOperatorRelationalAql (const TRI_aql_node_type_e);

#endif

// -----------------------------------------------------------------------------
// --SECTION--                                                       END-OF-FILE
// -----------------------------------------------------------------------------

// Local Variables:
// mode: outline-minor
// outline-regexp: "/// @brief\\|/// {@inheritDoc}\\|/// @page\\|// --SECTION--\\|/// @\\}"
// End:
