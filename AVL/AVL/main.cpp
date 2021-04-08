#include"AVL.cpp"

int main()
{
    Dictionary<int,int> t,v;
    t.insert(13);
    t.insert(24);
    t.insert(46);
    t.print();
    cout << endl << endl;
    t.insert(79);
    t.print();
    cout << endl << endl;
    t.change(79);
    t.print();
    cout << endl << endl;
    t.remove(79);
    t.inorder();

    v = t;
    cout << endl << endl;
    v.print();
}