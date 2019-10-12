#include"BTNode.h"
template<typename T>class BTree
{
    protected:
        int _size;
        int _order;
        BTNodePosi(T) _root;
        BTNodePosi(T) _hot;
        void solveOverflow(BTNodePosi(T));
        Void solveUnderflow(BTNodePosi(T));
    public:
        BTree(int order=3):_order(order),_size(0)
        {
            _root = new BTNode<T>();
        }
        ~BTree(){if(_root) release(_root);}
        int const order(){return _order;}
        int const size(){return _size;}
        BTNodePosi(T)& root(){return _root;}
        bool empty() const {return !root==0;}
        BTNodePosi(T) search(const T& e);
        bool insert(const T&e);
        bool remove(const T&e);
};
template<typename T>BTNodePosi(T) BTree<T>::search(const T& e)
{
    BTNodePosi(T) v=_root;
    _hot = NULL;
    while(v)
    {
        int r = v->key.search(e);
        if((0<=r)&&(e==v->key[r])) return v;
        _hot = v;v=v->child[r+1];
    }
    return NULL;
}