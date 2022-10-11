struct node{
    char d;
    unordered_map<char,node*> m;
    bool isterminal;

    node(char _d){
        d = _d;
        isterminal = false;
    }
};

struct trie{
    node * root;

    trie(){
        root = new node('\0');
    }

    void add(string s){
        node * temp = root;
        for(auto x : s){
            if(temp->m.count(x) == 0){
                node * n = new node(x);
                temp->m[x] = n;
            }
            temp = temp->m[x];
        }
        temp->isterminal = true;
    }

    bool search(string s){
        node * temp = root;
        for(auto x : s){
            if(temp->m.count(x) == 0){
                return false;
            }
            temp = temp->m[x];
        }
        return temp->isterminal == true;
    }
};


