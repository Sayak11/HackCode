#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coef;
    int exp;
    struct node *next;
};

void create(struct node **h)
{   
    struct node *ptr;
    struct node *cur;
    int i;
    for(i=0;i<4;i++)
    {
        cur=(struct node *)malloc(sizeof(struct node));
        cur->coef=rand()%10;
        cur->exp=rand()%2;
        cur->next=NULL;
        if((*h)==NULL)
        {
          *h=cur;
          ptr=cur;
        }
        else
        {
          ptr->next=cur;
          ptr=cur;
        }
    }
    
}

display(struct node *h)
{
  struct node *cur;
  printf("linked list:\t");
  for(cur=h;cur!=NULL;cur=cur->next)
  {
    printf("%d %d\t",cur->coef,cur->exp);
  }
}

void simp(struct node *h)
{ 
  struct node *ptr;
  struct node *prv;
  struct node *ptr1;
  for(ptr=h;ptr!=NULL;ptr=ptr->next)
  {   
      prv=ptr;
      for(ptr1=ptr->next;ptr1!=NULL;prv=ptr1,ptr1=ptr1->next)
      {   
          if(ptr1->exp==ptr->exp)
          {
              ptr->coef+=ptr1->coef;
              prv->next=ptr1->next;
              free(ptr1);
              ptr1=prv;
          }
      }
  }
}

void mul(struct node **h3,struct node *h1,struct node *h2)
{
    struct node *ptr1;
    struct node *ptr2;
    struct node *ptr3;
    struct node *cur;

    for(ptr1=h1;ptr1!=NULL;ptr1=ptr1->next)
    {
        for(ptr2=h2;ptr2!=NULL;ptr2=ptr2->next)
        {
            cur=(struct node *)malloc(sizeof(struct node));
            cur->coef=ptr1->coef*ptr2->coef;
            cur->exp=ptr1->exp+ptr2->exp;
            cur->next=NULL;
        
           if(*h3==NULL)
           {
              *h3=cur;
              ptr3=cur;
           }
           else
           {
              ptr3->next=cur;
              ptr3=cur;
            }
        }
    }
}

int main()
{
    struct node *h=NULL;
    struct node *h1=NULL;
    struct node *h3=NULL;
    create(&h);
    display(h);
    printf("\n");

    create(&h1);
    display(h1);
    printf("\n");

    mul(&h3,h,h1);
    display(h3);
    printf("\n");

    simp(h3);
    display(h3);
    printf("\n");

    return 0;
}