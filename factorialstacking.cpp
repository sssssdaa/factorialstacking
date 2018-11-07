    #include<iostream>
    using namespace std;

    typedef struct termen {int info;
                           struct termen *next;
                          } element;

    typedef struct { int length;
                     element *start,*current,*finalist;
                   } definition;

    definition *L=NULL;
    // Operations

    int push(definition **L,int value)
    {
    // NOTA 1

    }

    definition *push(definition *L,int value)
    {if (L==NULL) {definition *result=new definition;
                  result->length=1;
                  result->start=new element;
                  result->start->next=NULL;
                  result->start->info=value;
                  result->current=result->start;
                  result->finalist=result->start;
                  return result;}

    element *new_one=new element;
    new_one->info=value;
    new_one->next=NULL;
    L->finalist->next=new_one;
    L->finalist=new_one;
    L->current=new_one;
    L->length++;
    return L;
    }

    definition *pop(definition *L,int *old_value)
    {if (L==NULL) {return L;}
    *old_value=L->finalist->info;
    if (L->length==1) { delete L->current;
                        L->start=L->current=L->finalist=NULL;
                        L->length--;
                        return L;}
    element *carrier=L->start;
    while (carrier->next!=L->finalist) { carrier=carrier->next;}
    carrier->next=NULL;
    delete L->finalist;
    L->finalist=carrier;
    L->current=carrier;
    L->length--;
    return L;
    }


    int pop(definition **L,int *error)
    {
    // NOTA 2 !!

    }


    // Tools

    int showlist(definition *L)
    {
    if (L->length>=1) { cout<<endl;
                        element *carrier=L->start;
                        int cycles=L->length;
                        while (cycles>0) {cout<<carrier->info<<" ";
                                          carrier=carrier->next;
                                          cycles--;}
                        return 1;
                      }
    cout<<endl<<"Empty list";
    return 0;
    }

    int main()
    { int topvalue;
    cout<<" Build stack : ";
    for(int i=1;i<=3;i++) L=push(L,i);
    showlist(L);
    cout<<endl<<" Decrease stack :";
    while (L->start!=NULL)
    {L=pop(L,&topvalue);
     cout<<endl<<" Picked "<<topvalue<<endl<<"Generated : ";
     showlist(L);}
    return 1;}
