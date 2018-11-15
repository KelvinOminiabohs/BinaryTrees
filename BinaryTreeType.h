#include <iostream>
#include <string>

using namespace std;









struct binaryTreeNode
{
    int info;
    binaryTreeNode *llink;
    binaryTreeNode *rlink;
};


class binaryTreeType
{
public:
    
    bool isEmpty() const;
    void inorderTrav() ;
    void preorderTrav() ;
    void postorderTrav() ;
    void insert();
    //int leaves(binaryTreeNode *p);
    // int nodeCount();
    binaryTreeType();//default
    void deletetree(binaryTreeNode *p);
    int count = 0;
    void deletenode();
    int treenodecount();
    int treeleavecount();
protected:
    binaryTreeNode *root;
    
private:
    void inorder(binaryTreeNode *p) ;
    void preorder(binaryTreeNode *p) ;
    void postorder(binaryTreeNode *p) ;
    int nodecount (binaryTreeNode *p);
    int leavecount (binaryTreeNode *p);
    
};







bool binaryTreeType::isEmpty() const
{
    return(root==NULL);
}


binaryTreeType::binaryTreeType()
{
    root=NULL;
    
}



void binaryTreeType::inorderTrav()
{
    inorder(root);
}


void binaryTreeType::preorderTrav()
{
    preorder(root);
}


void binaryTreeType::postorderTrav()
{
    postorder(root);
}



void binaryTreeType::inorder(binaryTreeNode *p)
{
    
    if(p!=NULL)
    {
        inorder(p->llink);
        cout<<p->info<<" ";
        
        cout<<endl;
        inorder(p->rlink);
        
    }//end if
    
}


void binaryTreeType::preorder(binaryTreeNode *p)
{
    if(p!=NULL)
    {
        cout<<p->info<<" ";
        cout<<endl;
        preorder(p->llink);
        preorder(p->rlink);
    }//end if
}


void binaryTreeType::postorder(binaryTreeNode *p)
{
    if(p!=NULL)
    {
        postorder(p->llink);
        postorder(p->rlink);
        cout<<p->info<<" ";
        cout<<endl;
    }//end if
}



void binaryTreeType::insert()
{
    
    int insertItem;
    binaryTreeNode *current;
    binaryTreeNode *trailCurrent;
    binaryTreeNode *newNode;
    
    cout<<"Enter a number to be add to binary tree "<<endl;
    cin>>insertItem;
    newNode=new binaryTreeNode;
    //assert(newNode!=NULL);
    newNode->info=insertItem;
    newNode->llink=NULL;
    newNode->rlink=NULL;
    
    if(root==NULL)
        root=newNode;
    
    else
    {
        current=root;
        
        while(current!=NULL)
        {
            trailCurrent=current;
            
            if(current->info==insertItem)
            {
                cout<<"The insert item is already in the tree, no duplicates "<<insertItem<<endl;
                return;
            }
            
            else if(current->info>insertItem)
                current=current->llink;
            else
                current=current->rlink;
        }//end while
        
        
        
        if(trailCurrent->info>insertItem)
            trailCurrent->llink=newNode;
        
        else
            trailCurrent->rlink=newNode;
    }//end else
}//end insert



void binaryTreeType:: deletetree(binaryTreeNode *p)
{
    
    binaryTreeNode *current;
    binaryTreeNode *trailCurrent;
    binaryTreeNode *temp;
    
    if (p==NULL)
        cout << "Error: The node to be deleted does not exist."<< endl;
    
    if (p->llink==NULL && p->rlink== NULL)
    {
        temp = p;
        p = NULL;
        delete temp;
    }
    
    else if (p->llink == nullptr)
    {
        temp = p;
        p = temp->llink;
        delete temp;
    }
    
    else if (p->llink == NULL)
    {
        temp = p;
        p = temp->llink;
        delete temp;
    }
    else
    {
        current = p->llink;
        trailCurrent = NULL;
        while (current->rlink != NULL)
        {
            trailCurrent = current;
            current = current->rlink;
        }
        p->info = current->info;
        if (trailCurrent == NULL)
            p->llink = current->llink;
        
        else
            trailCurrent->rlink = current->llink;
        delete current;
        
    }//end else
    
    cout<<"Node has been deleted "<<endl;
}

void binaryTreeType:: deletenode()
{
    int deleteItem;
    binaryTreeNode *current;
    binaryTreeNode *trailCurrent;
    
    cout<<"What is the number do you want to delete? "<<endl;
    cin>>deleteItem;
    
    bool found= false;
    
    if (root==NULL)
        cout<<"cannot delete from empty tree "<<endl;
    else
    {
        current = root;
        trailCurrent = root;
        
        while (current != NULL && !found)
        {
            if (current->info == deleteItem)
                found = true;
            
            
            else
            {
                trailCurrent = current;
                if (current->info > deleteItem)
                    current = current->llink;
                else
                    current = current->rlink;
            }
        }// end of while loop
        
        
        if (current == nullptr)
            cout << "The item to be deleted is not in the tree."<< endl;
        
        else if(found)
        {
            if(current == root)
                deletetree(root);
            
            else if (trailCurrent->info > deleteItem)
                deletetree(trailCurrent->llink);
            
            else
                deletetree(trailCurrent->rlink);
        }
        
        else
            cout<<"the item to be deleted is not in the tree"<<endl;
        
        
    }
    
    
    
    
    
    
}


int binaryTreeType::nodecount(binaryTreeNode *p)
{
    
    if (p==NULL)
        return 0;
    else
        return 1 + nodecount(p->llink) + nodecount(p->rlink);
    
    
}

int binaryTreeType::treenodecount()
{
    return nodecount(root);
}



int binaryTreeType::leavecount(binaryTreeNode *p)
{
    if (p == NULL)      //if T is empty, return0
        return 0;
    
    else if (p->llink == NULL && p->rlink == NULL)
        return 1;
    
    else
        return leavecount(p->llink) + leavecount(p->rlink);  //recursive call to find more leaves
}

int binaryTreeType::treeleavecount()
{
    return leavecount(root);
