#include "graphedge.h"
#include "graphnode.h"

#include<iostream> // temporary

GraphNode::GraphNode(int id)
{
    //std::cout << "New GraphNode constructor" << std::endl;
    //_chatBot = std::make_shared<ChatBot>();
    _chatBot = std::make_unique<ChatBot>();
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    // delete chatbot
    _chatBot = nullptr;

    // delete edges (child and parent)
    for (auto& it : _childEdges)
    {
        //std::cout << "Delete one childedge " << it << std::endl;
        it = nullptr;
    }
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

/* happens only a single time during load answergraph */
void GraphNode::AddEdgeToChildNode(GraphEdge *edge)
{
    //_childEdges.push_back(edge);
    _childEdges.emplace_back(std::move(edge));
}

//// STUDENT CODE
////

void GraphNode::MoveChatbotHere(ChatBot &&chatbot)
{
    //std::cout << "MoveChatbotHere method" << std::endl;
    *_chatBot = std::move(chatbot);
    _chatBot->SetCurrentNode(this);
}


// tell chatbot to move from current node to new node
void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    //std::cout << "MoveChatbotToNewNode method" << std::endl;
    newNode->MoveChatbotHere(std::move(*_chatBot));
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
