#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

typedef struct Node{
    char ch;
    int frequency;
    Node *left, *right;
}Node;

typedef struct cmp{
    bool operator()(Node* i, Node* j){
        return i->frequency > j->frequency;
    }
}cmp;

class huffmanTree{
    public:
        ~huffmanTree(){
            //�Ҵ���� ��� �����
            releaseTree(root);
            root = nullptr;
            um.clear();
            info.clear();
            while (!pq.empty()) pq.pop();
        }
    public:
        const unordered_map<char, string>& Getinfo(){
            return info;
        }
    public:
        void Create(const string& str){
            //�� �� ����ϱ�
            for(const auto iter : str) ++um[iter];
            for(const auto iter: um){
                //�ϳ��� ������ ��忡 �����ϰ� �켱���� ť�� �ֱ�
                Node* newNode = new Node;
                newNode->left = nullptr;
                newNode->right = nullptr;
                newNode->ch = iter.first;
                newNode->frequency = iter.second;
                pq.push(newNode);
            }
            makeTree(); //���� �켱���� ť�� Ʈ�� �����
            string tmp = "";
            findTree(root, tmp);
        }
    private:
        void makeTree(){
            /*  ������ ���� �켱���� ť���� �󵵰� ����������
                2���� ������ �̰� ��� ��带 ����� ť�� �ٽ� ������� */
            int limit = pq.size() -1;
            for(int i=0;i<limit;++i){
                Node* newNode = new Node;
                newNode->ch = 0;
                newNode->right = pq.top(); pq.pop();
                newNode->left = pq.top(); pq.pop();
                newNode->frequency = newNode->right->frequency+newNode->left->frequency;
                pq.push(newNode);
            }
            root = pq.top();
        }
        void findTree(Node* p, string str){
            if(p == nullptr) return;
            findTree(p->left, str+'0');
            findTree(p->right, str+'1');
            //���ĺ��� �����ٸ�?
            if(p->ch != 0) info[p->ch] = str;
        }
        void releaseTree(Node* p){
            //�Ҵ������ϴ� �Լ�
            if(p == nullptr) return;
            releaseTree(p->left);
            releaseTree(p->right);
            delete p;
            p = nullptr;
        }
    private:
        Node* root = nullptr;
        unordered_map<char, int> um;
        unordered_map<char, string> info;
        priority_queue<Node*, vector<Node*>, cmp> pq;
};

int main(){
    string str;
    huffmanTree ht;

    cout << "���ڿ� �Է� : ";
    getline(cin, str, '#');

    ht.Create(str);
    unordered_map<char, string> info = ht.Getinfo();
    //cout << "������ ���ڿ� : " << str << "\n\n";
    cout << "���� ���� : \n";
    for(const auto iter : info) cout << iter.first << ": " << iter.second << endl;
    cout << "\n���� ���� : ";
    for(const auto iter : str) cout << info[iter] ;
}