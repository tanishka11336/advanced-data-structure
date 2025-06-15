#include <iostream>
using namespace std;
class bst
{
public:
    int rollno, cet_score;
    string name, surname;
    bst *lc, *rc;
    void accept();
    void insert(bst *root, bst *next);
    void display(bst *root);
    void search(bst *root, int l);
    void minimum_scored_student(bst *root);
    void maximum_score_student(bst *root);
    void non_iitian(bst *root);
    void iitian(bst *root);
    void mirrorimage(bst *root);
    void add(bst *root);
    void postorder(bst *root);
    void deletenode(bst *root, int key);
} *root = NULL, *stack[20];
void bst::accept()
{
    int ch;
    root = new bst;
    cout << "enetr the roll no of the student";
    cin >> root->rollno;
    cout << "enter the name of the student";
    cin >> root->name;
    cout << "enetr the surname of the student";
    cin >> root->surname;
    cout << "enetr the cet score of the student";
    cin >> root->cet_score;
    root->lc = root->rc = NULL;
}
void bst::insert(bst *root, bst *next)
{
    if (root == NULL)
        return;

    if (next->cet_score > root->cet_score)
    {
        if (root->rc == NULL)
        {
            root->rc = next;
        }
        else
        {
            insert(root->rc, next);
        }
    }
    else
    {
        if (next->cet_score < root->cet_score)
            if (root->lc == NULL)
            {
                root->lc = next;
            }
            else
            {
                insert(root->lc, next);
            }
    }
}
void bst::add(bst *root)
{
    bst *next = new bst;
    cout << "enetr the data for new node";
    cin >> next->rollno >> next->name >> next->surname >> next->cet_score;
    next->lc = next->rc = NULL;
    insert(root, next);
}

void bst::display(bst *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->rollno << "\t" << root->name << "\t" << root->surname << "\t" << root->cet_score << endl;
    display(root->lc);
    display(root->rc);
}
void bst::search(bst *root, int l)
{
    if (root == NULL)
    {
        return;
    }
    if (root->rollno == l)
    {
        cout << root->rollno << "\t" << root->name << "\t" << root->surname << "\t" << root->cet_score << endl;
        return;
    }
    search(root->lc, l);
    search(root->rc, l);
}
void bst::minimum_scored_student(bst *root)
{
    if (root == NULL)
    {
        return;
    }
    while (root->lc != NULL)
    {
        root = root->lc;
    }
    cout << root->rollno << "\t" << root->name << "\t" << root->surname << "\t" << root->cet_score << "\n";
}
void bst::maximum_score_student(bst *root)
{
    if (root == NULL)
    {
        return;
    }
    while (root->rc != NULL)
    {
        root = root->rc;
    }
    cout << root->rollno << "\t" << root->name << "\t" << root->surname << "\t" << root->cet_score << endl;
}
void bst::non_iitian(bst *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->rollno << "\t" << root->name << "\t" << root->surname << "\t" << root->cet_score << endl;
    non_iitian(root->lc);
    if(root->lc && root->lc->rc){
        non_iitian(root->lc->rc);
    }
}
void bst::iitian(bst *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->rollno << "\t" << root->name << "\t" << root->surname << "\t" << root->cet_score << endl;
    iitian(root->rc);
}
void bst::mirrorimage(bst *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        mirrorimage(root->lc);
        mirrorimage(root->rc);
        bst *temp = root->lc;
        root->lc = root->rc;
        root->rc = temp;
    }
}
void bst::postorder(bst *root)
{
    bst *array[100];
    bst *temp;
    int top = -1, i = 0;
    temp = root;
    if (root != NULL)
    {
        do
        {
            while (temp != NULL)
            {
                array[i] = temp;
                i++;
                top++;
                stack[top] = temp;
                temp = temp->rc;
            }
            if (top != -1)
            {
                temp = stack[top];
                temp = temp->lc;
                top--;
            }
        } while (top != -1 || temp != NULL);
    }
    for (int j = i - 1; j >= 0; j--)
    {
        cout << array[j]->rollno << "\t" << array[j]->name << "\t" << array[j]->surname << "\t" << array[j]->cet_score << endl;
    }
}
void bst::deletenode(bst *root, int key)
{ 
    if (root == NULL)
        return;

    if (root->lc->rollno == key && root->lc!=NULL && root->lc->lc==NULL && root->rc==NULL)
    {
        root->lc = NULL;
        delete root->lc; 
        return;
    }
    else if (root->rc->rollno == key && root->rc!=NULL && root->rc->rc==NULL && root->rc->lc==NULL)
    {
        root->rc = NULL;
        delete root->lc;
        return;
    }
    deletenode(root->lc, key);
    deletenode(root->rc, key);
}

int main()
{
    bst k;
    int b;
    do
    {
        cout << "1.insert a node\n2.add  new node\n3.display in preorder\n4.search a node\n5.minimum scored student\n6.maximum scored student\n7.display only  iitian students\n8.display non iitian students\n9.delete a node\n";
        cin >> b;
        switch (b)
        {
        case 1:
            k.accept();
            break;
        case 2:
            k.add(root);
            break;
        case 3:
            cout << "rollnno\tname\tsurname\tcet_score\n";
            k.postorder(root);
            break;
        case 4:
            k.search(root, 12);
            break;
        case 5:
            k.minimum_scored_student(root);
            break;
        case 6:
            k.maximum_score_student(root);
            break;
        case 7:
            k.iitian(root);
            break;
        case 8:
            k.non_iitian(root);
            break;
        case 9:
            int key;
            cout << "enetr the rollno of the studennt which you want to delete ";
            cin >> key;
            k.deletenode(root, key);
        }
    } while (b != 0);
    return 0;
}