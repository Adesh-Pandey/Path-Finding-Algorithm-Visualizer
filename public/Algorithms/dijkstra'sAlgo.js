
let shortFromStart=[];
let prev=[];
let visited=[];
let LocalWalk=[];
let size=0;

const allVisited=()=>{
    for (let i = 0; i < visited.length; i++) {
        if(visited[i]==0 && LocalWalk[i]!=-1){
            return true;
        }       
    }
    return false;
}


const minimumUnvisited=()=>{

    let mini=Number.MAX_SAFE_INTEGER;
    let loc=mini;

    for (let inde = 0; inde < shortFromStart.length; inde++) {
        
        if(mini>shortFromStart[inde] && visited[inde]!=1){
            mini=shortFromStart[inde];
            loc=inde
        }
    }
    return loc;

}

let curr;

const walkable=(val,cur,ref)=>{
    if(LocalWalk[val]!=-1){
        if(shortFromStart[val]>shortFromStart[ref]+LocalWalk[val]){
            shortFromStart[val]=shortFromStart[ref]+LocalWalk[val];
            prev[val]=cur;
            
    }
}
}



const Dijkstra=(vertices,start,final,walk,n,m,classOnStep,delay)=>{
    vertices=document.querySelectorAll(".vertices")
    size=n*m;
    for (let index = 0; index < size; index++) {

        shortFromStart[index]=Number.MAX_SAFE_INTEGER; 
        visited[index]=0;
        prev[index]=0;
        LocalWalk[index]=walk[index];
    }

    let i=0;
    shortFromStart[start]=0;

    const showPath=(node,i)=>{

        if(node==vertices[start])
        {
            setTimeout(() => {
                node.classList.remove(classOnStep)
             node.classList.add(delay==0?"instantPath":"path");
        }, delay*i);
            return;
        }
        i--;
            showPath(prev[node.id],i);
            
            setTimeout(() => {
                node.classList.remove(classOnStep)
            node.classList.add(delay==0?"instantPath":"path");
        }, delay*i);
        
        return;
    
    }

    while(allVisited()){
        
        i++;
            let ans=minimumUnvisited();
            if(ans==Number.MAX_SAFE_INTEGER)
                break;

            curr=vertices[ans];
        
            let up= (ans-m)<0?-1:(ans-m);
            let down=(ans+m)>size-1?-1:(ans+m);
            let left=(ans-1)<0?-1:(ans-1);
            let right=(ans+1)>size-1?-1:(ans+1);
        
        
            up==-1?0:walkable(up,curr,ans);
            down==-1?0:walkable(down,curr,ans);
            left==-1 || (ans+1)%m==1?0:walkable(left,curr,ans);
            right==-1 || (ans+1)%m==0?0:walkable(right,curr,ans);

            visited[ans]=1;
        
            if(delay!==0){
            setTimeout(() => {
                if(ans==final)
                {   
                    showPath(curr,shortFromStart[final]+1);
                    
                }else{
                ans==start?0:vertices[ans].classList.add(classOnStep);  
            }
        }, i*delay); }
        else{
            if(ans==final)
                {   
                    showPath(curr,shortFromStart[final]+1);
                    
                }else{
                ans==start?0:vertices[ans].classList.add(classOnStep);  
            }
        }
        if(ans==final){
            break;
        }
    }
    return i;

}
export default Dijkstra;