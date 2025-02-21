#include <iostream>
using namespace std;
int count = 1;
class stud
{
public:
    stud *lc, *rc;
    int rollno;
    string name;
    string surname;
    void create();
    void insert(stud *root, stud *next);
    void display(stud *root);
    void displayparent(stud *root);
    void displayleaf(stud *root);
    int calculatelength(stud *root);
    void displaypreorder(stud *root);
    void mirrorimage(stud *root);
    void updatetree(stud *root);
    void search(stud *root,int k);
    void postorder(stud *root);
} *root = NULL, t, *stack[100];
void stud::create()
{
    int ch;
    root = new stud;

    cout << "enter the name of the employee";
    cin >> root->name;
    cout << "enetr the surname of the employee";
    cin >> root->surname;
    cout << "enetr the rollno of the employee";
    cin >> root->rollno;
    root->lc = NULL;
    root->rc = NULL;
    do
    {
        cout << "do you want to insert another node press 1 or yes and 0 for no";
        cin >> ch;
        if (ch == 1)
        {
            stud *next = new stud;
            cout << "enetr the name of the next employee";
            cin >> next->name;
            cout << "enetr the surname of the employee";
            cin >> next->surname;
            cout << "enetr the rollno of the next employeee";
            cin >> next->rollno;
            next->lc = next->rc = NULL;
            insert(root, next);
            count++;
        }
    } while (ch == 1);
}
void stud::insert(stud *root, stud *next)
{
    char choice;
    cout << "enter on which side of " << root->rollno << "do you want to insert new node(l/r)";
    cin >> choice;
    if (choice == 'l' || choice == 'L')
    {
        if (root->lc == NULL)
        {
            root->lc = next;
        }
        else
        {

            insert(root->lc, next);
        }
    }
    else if (choice == 'R' || choice == 'r')
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
}
// void stud::display(stud *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     else
//     {
//         display(root->lc);
//         cout << root->name << "\t" << root->surname << "\t" << root->rollno << endl;
//         display(root->rc);
//     }
// }
void stud::displayparent(stud *root)
{
    cout << root->name << "\t" << root->surname << "\t" << root->rollno << endl;
}
void stud::displayleaf(stud *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->lc == NULL && root->rc == NULL)
    {
        cout << root->name << "\t" << root->surname << "\t" << root->rollno << endl;
    }
    displayleaf(root->lc);
    displayleaf(root->rc);
}

void stud::display(stud *root)
{
    stud *temp;
    temp = root;
    int top = -1;
    if (root != NULL)
    {
        do
        {
            while (temp != NULL)
            {
                top++;
                stack[top] = temp;
                temp = temp->lc;
            }
            if (top != -1)
            {
                temp = stack[top];
                top--;
                cout << temp->rollno << "\t" << temp->name << "\t" << temp->surname << endl;
                temp = temp->rc;
            }
        }

        while (top != -1 || temp != NULL);
    }
}
void stud::displaypreorder(stud *root)
{
    int top = -1;
    stud *temp = root;
    if (root != NULL)
    {
        do
        {
            while (temp != NULL)
            {
                top++;
                stack[top] = temp;
                cout << temp->rollno << "\t" << temp->name << "\t" << temp->surname << endl;
                temp = temp->lc;
            }
            if (top != -1)
            {
                temp = stack[top];
                top--;
                temp = temp->rc;
            }
        } while (temp != NULL || top != -1);
    }
}

int stud::calculatelength(stud *root)
{
    int lht, rht, fht;
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        lht = calculatelength(root->lc);
        rht = calculatelength(root->rc);
        if (lht > rht)
        {
            fht = lht + 1;
        }
        else
        {
            fht = rht + 1;
        }
    }
    return fht;
}
void stud::mirrorimage(stud *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        mirrorimage(root->lc);
        mirrorimage(root->rc);
        stud *temp = root->lc;
        root->lc = root->rc;
        root->rc = temp;
    }
}
void stud::updatetree(stud *root)
{
    if (root == NULL)
    {
        return;
    }
        int Rollno;
        string newname, newsurname;
        cout<<"enter rollno";
        cin>>Rollno;
        cout<<"enter new name";
        cin>>newname;
        cout<<"enetr new surname";
        cin>>newsurname;
            if (root->rollno == Rollno)
            {
                root->name = newname;
                root->surname = newsurname;
                return;
            }
            updatetree(root->lc);
            updatetree(root->lc);
        }
    void stud::search(stud* root,int k){
        if(root==NULL){
            return;
        }
        if(root->rollno==k){
            cout<<root->rollno<<"\t"<<root->name<<"\t"<<root->surname<<"\n";
            return;
        }
 search(root->lc,k);
 search(root->rc,k);
    }
void stud::postorder(stud *root){
stud *array[100];
stud *temp;
int top=-1,i=0;
temp=root;
if(root==NULL){
    return ;
}
do{
    while(temp!=NULL){
        array[i]=temp;
        i++;
        top++;
         temp=temp->rc;
         stack[top]=temp;
    }
    if(top!=-1){
        temp=stack[top];
        temp=temp->lc;
        top--;
    }
}
while(top!=-1 && temp!=NULL);
for(int j=i-1;j>=0;j--){
    cout<<array[j]<<endl;
}
}
int main()
{
    int ch;
    do
    {
        cout << "\n1.insert a node\n2.display\n3.display parent only\n4.display only leaf node\n5.display the height of the tree\n6.display by preorder\n7.display by post order\n8.mirror image\n9.update tree\n10search a node";
        cin >> ch;
        switch (ch)
        {
        case 1:
            t.create();
            break;
        case 2:
            t.display(root);
            break;
        case 3:
            t.displayparent(root);
            break;
        case 4:
            t.displayleaf(root);
            break;
        case 5:
            if (root != NULL)
            {
                int j = t.calculatelength(root);
                cout << "height of the tree is " << j << endl;
            }
            break;
        case 6:
            t.displaypreorder(root);
            break;
        case 7:
            t.postorder(root);
            break;
        case 8:
            t.mirrorimage(root);
            break;
        case 9:
            t.updatetree(root);
            break;
        case 10:
        int k;
        cin>>k;
        t.search(root,k);
        }
    } while (ch != 0);
}