#include <bits/stdc++.h>
using namespace std;
#ifdef Rashad
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif
#define fastio                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);

#define ll long long
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define vll vector<ll>
#define vi vector<int>
#define pii pair<int,int>
#define OO 2e9
#define endl "\n"
const int dx[]{0, 1, 0, -1, -1, -1, 1, 1};
const int dy[]{1, 0, -1, 0, -1, 1, -1, 1};
template <typename T>
struct Node{
    T data{};
    Node* next{};
    Node* prev{};
    explicit Node(T data) : data(data){};
};
template <typename T>
class LinkedList {
private:
    Node<T>* head{};
    Node<T>* tail{};
    int length = 0;
public:
    LinkedList()= default;
    LinkedList(const LinkedList&) = delete;
    LinkedList&operator=(const LinkedList &another) = delete;
    ~LinkedList();
    void printlength() const {
        cout<<length<<endl;
    }
    static void link(Node<T>*first,Node<T>*second);
    void print();
    void print_reverse();
    void insert_end(T value);
    void insert_front(T value);
    Node<T>* get_nth(int index);
    int Search(T value);
    Node<T>* get_nth_back(int n);
    void delete_front();
    void delete_end();
    void delete_nth(int index);
    void delete_value(T value);
    void delete_node(const Node<T>*node);
    void reverse_nodes();
    void insert_sorted(T value);
    void embed_after(Node<T>*node,T value);
    T end(){
      return tail->data;
    }
    T start(){
      return head->data;
    }
};

template <typename T> istream &operator>>(istream &input, vector<T> &data) {
  for (T &x : data)
    input >> x;
  return input;
}
template <typename T> ostream &operator<<(ostream &output, const vector<T> &data) {
  for (const T &x : data)
    output << x << " ";
  return output;
}
int mod = 1000000007;
int fast_power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res *= a % mod;
        a *= a % mod;
        b >>= 1;
    }
    return res;
}
vector<int> primeFactors(int n) {
    vector<int> factors;
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 2) {
        factors.push_back(n);
    }
    return factors;
}
// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z

void solve() {
  int n;cin>>n;
  LinkedList<ll> v;
  for (int i = 0; i < n; i++) {
    ll x;cin>>x;
    v.insert_end(x);
  }
  int q;cin>>q;
  while(q--){
    int choise, x;cin>>choise>>x;
    // 1 to shift
    // 2 to search
    if(choise == 1){
      if(x>0){
        while(x--){
          v.insert_front(v.end());
          v.delete_end();
        }
        /*v.print();*/
      }else{
        while(x++){
          v.insert_end(v.start());
          v.delete_front();
        }
        /*v.print();*/
      }
    }else{
      int value = v.Search(x);
      if(value == -1)
        cout<<-1<<endl;
      else {
        cout<<value+1<<endl;
      }
    }
  }
}
int32_t main() {
    //  freopen("whereami.in", "r", stdin);
    //  freopen("whereami.out", "w", stdout);
    fastio
    int t = 1;
    cin>>t;
    while (t--)
        solve();
    return 0;
}
template <typename T>
LinkedList<T>::~LinkedList() {
    while(head){
        Node<T>*current = head->next;
        delete head;
        head=current;
    }
}
template <typename T>
void LinkedList<T>::print() {
    for(Node<T>*cur=head;cur;cur = cur->next){
        cout<<cur->data<<" ";
    }
    cout<<endl;
}
template <typename T>
void LinkedList<T>::print_reverse() {
    for(Node<T>*cur=tail;cur;cur=cur->prev)
        cout<<cur->data<<" ";
    cout<<endl;
}
template <typename T>
void LinkedList<T>::link(Node<T> *first, Node<T> *second) {
    if(first)
        first->next=second;
    if(second)
        second->prev=first;
}
template <typename T>
void LinkedList<T>::insert_end(T value) {
    auto* item = new Node(value);
    if(!head)
        head = tail = item;
    else{
        link(tail,item);
        tail = item;
    }
    length++;
}
template <typename T>
void LinkedList<T>::insert_front(T value) {
    auto* item = new Node(value);
    if(!head)
        head = tail = item;
    else{
        link(item,head);
        head = item;
    }
    length++;
}
template <typename T>
Node<T>* LinkedList<T>::get_nth(int const index) {
    int cnt = 0;
    for (Node<T> *cur = head; cur; cur = cur->next)
        if (cnt++ == index)
            return cur;
    return nullptr;
}
template <typename T>
int LinkedList<T>::Search(T value) {
    int index = 0;
    for(Node<T>* cur =head;cur;cur=cur->next,index++)
        if(cur->data==value)
            return index;
    return -1;
}
template <typename T>
Node<T>* LinkedList<T>::get_nth_back(int n) {
    if(length<n)
        return nullptr;
    return get_nth(length - (n + 1));
}
template <typename T>
void LinkedList<T>::delete_node(const Node<T> *node) {
    --length;
    delete node;
}
template <typename T>
void LinkedList<T>::delete_front() {
    if(!head)
        return;
    Node<T>*cur=head->next;
    delete_node(head);
    head=cur;
    if(head)
        head->prev= nullptr;
    else if(!length)
        tail= nullptr;
}
template <typename T>
void LinkedList<T>::delete_end() {
    if(!head)
        return;
    Node<T>*cur = tail->prev;
    delete_node(tail);
    tail=cur;
    if(tail)
        tail->next = nullptr;
    else if(!length)
        head = nullptr;
}
template <typename T>
void LinkedList<T>::delete_nth(int index) {
    if(index<0||index>length)
        cout<<"Error. No such nth node\n";
    else if(index==0)
        delete_front();
    else if(index==length-1)
        delete_end();
    else{
        Node<T>*cur = get_nth(index);
        link(cur->prev,cur->next);
        delete_node(cur);
    }
}
template <typename T>
void LinkedList<T>::delete_value(T value) {
    delete_nth(Search(value));
}
template <typename T>
void LinkedList<T>::reverse_nodes() { //single linked list
    if(length<=1)
        return;
    Node<T>*cur=tail;
    while(cur!= nullptr){
        Node<T>*next=cur->next;
        cur->next=cur->prev;
        cur=next;
    }
    Node <T>*aux=tail;
    tail=head;
    head=aux;
}
template <typename T>
void LinkedList<T>::embed_after(Node<T> *node_before, T value) {
    Node<T>*middle=new Node(value);
    ++length;
    Node<T>*node_after=node_before->next;
    link(node_before,middle);
    link(middle,node_after);
}
template <typename T>
void LinkedList<T>::insert_sorted(T value) {
    if(!length||value<=head->data)
        insert_front(value);
    else if(tail->data<=value)
        insert_end(value);
    else{
        for(Node<T>*cur=head;cur;cur=cur->next){
            if(value<=cur->data){
                embed_after(cur->prev,value);
                break;
            }
        }
    }
}
