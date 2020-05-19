#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot
{
    private:
        // data handles (owned)
        wxBitmap *_image; // avatar image

        // data handles (not owned)
        GraphNode *_currentNode;
        GraphNode *_rootNode; /* root node important when reaching deadend */
        ChatLogic *_chatLogic;

        // proprietary functions
        /* number of characters to change to covert string one to sting two
         the one with the smallest levensthtein distance is the best fit answer
         */
        int ComputeLevenshteinDistance(std::string s1, std::string s2);

    public:
        // constructors / destructors
        ChatBot();                     // constructor WITHOUT memory allocation
        ChatBot(std::string filename); // constructor WITH memory allocation
        ~ChatBot();                    // destructor

        //// STUDENT CODE
        ////
        
        ChatBot(const ChatBot &source);             // copy constructor
        ChatBot &operator=(const ChatBot &source);   //copy assignment operator
        ChatBot(ChatBot &&source);                  // move constructor
        ChatBot &operator=(ChatBot &&source);       // move assignment operator
        
        ////
        //// EOF STUDENT CODE

        // getters / setters
        void SetCurrentNode(GraphNode *node);
        void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
        void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
        wxBitmap *GetImageHandle() { return _image; }

        // communication
        void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */
