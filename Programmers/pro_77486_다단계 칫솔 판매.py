from collections import defaultdict
import math

def solution(enroll, referral, seller, amount):
    #get child parent
    dictChild = defaultdict(list)
    dictParent = defaultdict(str)    
    for child, parent in zip(enroll,referral):
        dictParent[child]=parent
        dictChild[parent].append(child)

    #get amount from leaf
    dictAmount = defaultdict(int)
    for man, amt in zip(seller,amount):
        money = amt*100
        dictAmount[man]+=money
        while(money):            
            moneyUp = math.floor(money*0.1)
            if(moneyUp):
                dictAmount[man]-=moneyUp
                dictAmount[dictParent[man]]+=moneyUp
                man = dictParent[man]
                money = moneyUp
            else:
                break
                
    return [dictAmount[x] for x in enroll]