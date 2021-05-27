
#include "Node.h"

class LlistaDoble
{
    public:
        LlistaDoble();
        ~LlistaDoble();

		bool empty() const;
		Node* begin() const;
		Node* rbegin() const;
		Node* push_front(const int& valor);
		Node* erase(Node* posicio);
    private:
        Node* m_primer;
		Node* m_ultim;
};