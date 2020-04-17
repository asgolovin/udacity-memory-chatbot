#include "graphnode.h"
#include "graphedge.h"
#include <iostream>

GraphNode::GraphNode(int id) {
  // std::cout << "GraphNode Constructor\n";
  _id = id;
}

GraphNode::~GraphNode() {
  //// STUDENT CODE
  ////

  // std::cout << "GraphNode Destructor\n";

  ////
  //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token) { _answers.push_back(token); }

void GraphNode::AddEdgeToParentNode(GraphEdge *edge) {
  _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge) {
  _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot chatbot) {
  _chatBot = std::move(chatbot);
  _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode) {
  newNode->MoveChatbotHere(std::move(_chatBot));
  //_chatBot = nullptr; // invalidate pointer at source
}

void GraphNode::ReceiveMessageFromUser(std::string message) {
  _chatBot.ReceiveMessageFromUser(message);
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index) {
  //// STUDENT CODE
  ////

  return (_childEdges[index]).get();

  ////
  //// EOF STUDENT CODE
}