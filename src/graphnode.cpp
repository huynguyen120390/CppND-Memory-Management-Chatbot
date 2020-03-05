#include "graphedge.h"
#include "graphnode.h"
#include <iostream>


GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{   
    std::cout << "Graph Node Destructor" << std::endl;
    //// STUDENT CODE
    ////

    //delete _chatBot; 

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot chatBot)
{
    _chatBot.reset(new ChatBot());
    *_chatBot = std::move(chatBot);
    _chatBot->SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{   
    newNode->MoveChatbotHere(std::move(*_chatBot));
    _chatBot.reset(); // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}