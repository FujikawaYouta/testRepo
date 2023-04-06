#when the boat is at this side(1)
#the possible states include
statesAvailable1=((3,3,1),(3,2,1),(3,1,1),
                 (3,0,1),(2,2,1),(1,1,1),
                 (0,3,1),(0,2,1),(0,1,1)
                 )
#when the boat is at the other side(0)
#the possible states include
statesAvailable0=((3,2,0),(3,1,0),(3,0,0),
                 (2,2,0),(1,1,0),(0,3,0),
                 (0,2,0),(0,1,0),(0,0,0)
                 )
def depthFirstSearch(startState:tuple,path:list,visitedStates:set):
    possibleStates=[]
    if path[-1]==(0,0,0) and (0,0,0) in visitedStates:
        print(path)
        return None
    if startState[2]==1:
        for i in range(0,5):
            m=0
            c=0
            b=0
            if i==0:
                m=startState[0]-1
                n=startState[1]-1
            elif i==1:
                m=startState[0]-2
                n=startState[1]
            elif i==2:
                m=startState[0]
                n=startState[1]-2
            elif i==3:
                m=startState[0]-1
                n=startState[1]
            elif i==4:
                m=startState[0]
                n=startState[1]-1
            stateTemp=(m,n,b)
            if stateTemp in statesAvailable0 and stateTemp not in visitedStates :
                visitedStates.add(stateTemp)
                possibleStates.append(stateTemp)
                path.append(stateTemp)
                depthFirstSearch(stateTemp,path,visitedStates)
                path.pop()
    else:
        for i in range(0,5):
            m=0
            c=0
            b=1
            if i==0:
                m=startState[0]+1
                n=startState[1]+1
            elif i==1:
                m=startState[0]+2
                n=startState[1]
            elif i==2:
                m=startState[0]
                n=startState[1]+2
            elif i==3:
                m=startState[0]+1
                n=startState[1]
            elif i==4:
                m=startState[0]
                n=startState[1]+1
            stateTemp=(m,n,b)
            if stateTemp in statesAvailable1 and stateTemp not in visitedStates :
                visitedStates.add(stateTemp)
                possibleStates.append(stateTemp)
                path.append(stateTemp)
                depthFirstSearch(stateTemp,path,visitedStates)
                path.pop()
    return None

if __name__ == '__main__':
    startState=(3,3,1)
    path=[startState]
    visitedStates=set()
    visitedStates.add(startState)
    depthFirstSearch(startState,path,visitedStates)