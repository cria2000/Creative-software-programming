#define NUM_OF_CHAT 10 
#include<string.h>
class ReplyAdmin{
	std::string* chats;
public:
	ReplyAdmin(){chats=new std::string[NUM_OF_CHAT]();
		for(int i=0;i<(NUM_OF_CHAT);i++){
			chats[i]="0";}
	}
	~ReplyAdmin(){delete[] chats;
		}
        int getChatCount();
        bool addChat(std::string _chat);
        bool removeChat(int _index);
        bool removeChat(int* _indices, int _count);
        bool removeChat(int _start, int _end);
	int printChat(int num);
};

       

