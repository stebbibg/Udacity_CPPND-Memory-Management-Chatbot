#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>
#include <iostream>
#include <memory>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    std::shared_ptr<wxBitmap> _image;
    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;
    //std::shared_ptr<ChatLogic> _chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                      // constructor WITHOUT memory allocation
    ChatBot(std::string filename);  // constructor WITH memory allocation
    ChatBot(const ChatBot& other);  // Copy constructor
    ChatBot& operator=(const ChatBot& other); // Copy assignment operator
    ChatBot(ChatBot&& other) noexcept;          // Move constructor
    ChatBot& operator=(ChatBot&& other) noexcept; // Move assigment operator
    
    ~ChatBot();

    //// STUDENT CODE
    ////
    


    ////
    //// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    // TODO! THIS NEEDS TO BE CALLED
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }

    ChatLogic* GetChatLogicHandle() { 
        return _chatLogic; 
    }

    
    std::shared_ptr<wxBitmap> GetImageHandle() {
        return _image; 
    }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */
