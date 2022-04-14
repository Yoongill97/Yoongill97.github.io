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
            //할당받은 노드 지우기
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
            //빈도 수 기록하기
            for(const auto iter : str) ++um[iter];
            for(const auto iter: um){
                //하나씩 꺼내서 노드에 저장하고 우선순위 큐에 넣기
                Node* newNode = new Node;
                newNode->left = nullptr;
                newNode->right = nullptr;
                newNode->ch = iter.first;
                newNode->frequency = iter.second;
                pq.push(newNode);
            }
            makeTree(); //만든 우선순위 큐로 트리 만들기
            string tmp = "";
            findTree(root, tmp);
        }
    private:
        void makeTree(){
            /*  위에서 만든 우선순위 큐에서 빈도가 작은순으로
                2개씩 꺼내서 이걸 담는 노드를 만들고 큐에 다시 집어넣음 */
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
            //알파벳을 만난다면?
            if(p->ch != 0) info[p->ch] = str;
        }
        void releaseTree(Node* p){
            //할당해제하는 함수
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

    cout << "문자열 입력 : ";
    getline(cin, str, '#');

    ht.Create(str);
    unordered_map<char, string> info = ht.Getinfo();
    //cout << "압축할 문자열 : " << str << "\n\n";
    cout << "문자 정보 : \n";
    for(const auto iter : info) cout << iter.first << ": " << iter.second << endl;
    cout << "\n압축 정보 : ";
    for(const auto iter : str) cout << info[iter] ;
}