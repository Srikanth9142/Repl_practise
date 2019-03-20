#include <stdio.h>
#include<stdlib.h>
struct node{ 
  int data; 
  struct node *left,*right; 
}; 
int big(int a, int b) 
{ 
  return a>b?a:b;
}
int hei(struct node *t){ 
  if(t==NULL) 
    return -1; 
  else if(t->left==NULL&&t->right==NULL) 
    return 0; 
  else if(t->left==NULL) 
    return 1+hei(t->right); 
  else if(t->right==NULL) 
    return 1+hei(t->left); 
  else 
    return 1+big(hei(t->left),hei(t->right)); 
}
struct node *ll(struct node *t)
{ 
  struct node *temp; 
  temp=t->left; 
  t->left=NULL; 
  if(temp->right==NULL) 
    temp->right=t; 
  else 
  { 
    t->left=temp->right; 
    temp->right=t; 
  } 
  temp->right=t; 
  return temp; 
}
struct node *rr(struct node *t) 
{ 
  struct node *temp,*temp1; 
  temp=t->right; 
  t->right=NULL; 
  if(temp->left==NULL) 
    temp->left=t; 
  else 
  { 
    temp1=temp->left; 
    temp->left=t; 
    t->right=temp1; 
  } 
  return temp; 
}
struct node *lr(struct node *t) 
{ 
  t->left=rr(t->left); 
  return ll(t); 
} 
struct node *rl(struct node *t){ 
  t->right=ll(t->right); 
return rr(t); 
} 
struct node *findmin(struct node *t) 
{ 
  if(t==NULL)
    return NULL; 
  if(t->left==NULL) 
    return t; 
  else 
    return findmin(t->left); 
}
struct node *insert(struct node *t, int x)
{ 
  if(t==NULL)
  { 
    t=malloc(sizeof(struct node)); 
    t->data=x; 
    t->left=t->right=NULL; 
    return t; 
  } 
  else if(x<t->data){ 
    t->left=insert(t->left,x); 
    if(hei(t->left)-hei(t->right)==2||hei(t->left)-hei(t->right)==-2) 
    if(x<t->left->data) 
      t=ll(t); 
    else
      t=lr(t);
    }
  
  else if(x>t->data) 
  { 
    t->right=insert(t->right,x); 
    if(hei(t->left)-hei(t->right)==2||hei(t->left)-hei(t->right)==-2) 
    if(x<t->right->data) 
      t=rr(t); 
    else{ 
     t=rl(t);} 
  } 
  else{ 
    printf("element exists\n");
  } 
  return t; 
}
void print(struct node *t){ 
  if(t) 
  { 
    printf("%d",t->data); 
    print(t->left); 
    print(t->right); 
    } 
}
struct node * del(struct node *t, int e) 
{ 
  struct node *temp;
  if(t==NULL) 
    return t; 
  else if(e<t->data){ 
    t->left=del(t->left,e); 
    if(hei(t->right)-hei(t->left)==2)
    if(t->right->right) 
      t=rr(t); 
    else{
      t=rl(t);} 
    } 
  else if(e>t->data){ 
    t->right=del(t->right,e); 
    if(hei(t->right)-hei(t->left)==2) 
    if(t->left->left) 
      t=ll(t); 
    else 
      {t=lr(t);} 
    } 
    else
    { 
      if(t->left==NULL&&t->right==NULL) 
      { 
        free(t); 
        return NULL; 
      }
      else if(t->left!=NULL&&t->right!=NULL) 
      { 
        temp=findmin(t->right); 
        t->data=temp->data; 
        t->right=del(t->right,temp->data); 
      } 
      else if(t->left==NULL) 
      { 
        t->data=t->right->data; 
        free(t->right);
        t->right=NULL; 
      } 
      else { 
        t->data=t->left->data; 
        free(t->left);
        t->left=NULL; 
        } 
    } 
  return t; 
}
int search(struct node *t, int ele) 
{ 
  if(t==NULL) 
    return 0; 
  else if(ele<t->data) 
    search(t->left,ele); 
  else if(ele>t->data) 
    search(t->right,ele); 
  else 
    return 1; 
} 
int main() 
{ 
  struct node *root=NULL; 
  int e;
  int ch; 
  while(1)
  { 
    printf("MENU\n"); 
    printf("1.insert\n2.display\n 3.delete\n4.search\n5.any other"); 
    printf("enter your choice"); 
    scanf("%d",&ch); 
    switch(ch){ 
      case 1: printf("enter element to be inserted"); 
              scanf("%d",&e); 
              root=insert(root,e); 
              break; 
      case 2:if(root==NULL) 
                printf("tree is empty\n"); 
              else{
                print(root);} 
              break; 
      case 3: printf("enter element to be deleted"); 
              scanf("%d",&e); 
              if(search(root,e)){ 
                root=del(root,e); 
                printf("%d is deleted\n",e);
              } 
              else{
                printf("element not found cannot be delted\n");} 
              break; 
    case 4: printf("enter element to be searched\n"); scanf("%d",&e); 
      if(root==NULL) 
        printf("tree is empty\n"); 
      else if(search(root,e)) 
        printf("ele found\n"); 
      else{ 
        printf("ele not found\n"); }
      break; 
    default:exit(0); 
    }
  } 
  return 0;
}
