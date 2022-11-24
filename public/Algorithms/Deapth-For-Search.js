let prev=[];
let initial=0;



const findDistance=(num,i)=>{

    if(num==initial){
        return ++i;
    }
    i++;
    return findDistance(Number(prev[num].id),i);
}
const dfs=(vertices,start,final,walk,n,m,classOnStep,delay)=>{
    
    initial=start;
    let visited=[];
    for (let i = 0; i < vertices.length; i++) {
        visited[i] = 0;
        prev[i]=0;
    }
    let dfsList=[];
    dfsList.push(start);
    // dfsList.push(null);
    let size=n*m;
    
    let i=0;
    let extraPathTimeCounter=0
    const showPath=(index,i)=>{
        extraPathTimeCounter++;
        if(index==start)
        {   
            vertices[index].classList.remove(classOnStep)
            vertices[index].classList.add(delay==0?"instantPath":"path");
            return;
        }
        i--;
            showPath(Number(prev[index].id),i);
            setTimeout(() => {
                vertices[index].classList.remove(classOnStep)
                vertices[index].classList.add(delay==0?"instantPath":"path");
        },delay*i);
        
        return;
    
    }
    let last=0;

    while(dfsList.length!=0){
        i++;

        let currNode=0;
        currNode=dfsList.shift();
        if(currNode==null){
            // dfsList.length!=0?dfsList.push(null):0;
            continue;
        }
        let up= (currNode-m)<0?-1:(currNode-m);
        let down=(currNode+m)>size-1?-1:(currNode+m);
        let left=(currNode-1)<0?-1:(currNode-1);
        let right=(currNode+1)>size-1?-1:(currNode+1);

        if(up!=-1 && walk[up]!=-1 && visited[up]==0)

        {
           
            if(dfsList.indexOf(up)!==-1){
                dfsList.filter((x)=>{return x!==up})
           }
           dfsList.unshift(up);prev[up]=vertices[currNode]
               
        };

        if(left!=-1 && walk[left]!=-1 && (currNode)%m!=0  && visited[left]==0 )
        {
            if(dfsList.indexOf(left)!==-1){
                 dfsList.filter((x)=>{return x!==left})
            }
            dfsList.unshift(left);prev[left]=vertices[currNode]
                
            };
        
        if(right!=-1 && walk[right]!=-1 && (currNode+1)%m!=0 && visited[right]==0)
        {
            if(dfsList.indexOf(right)!==-1){
                 dfsList.filter((x)=>{return x!==right})
            }
            dfsList.unshift(right);prev[right]=vertices[currNode]
                };

        if(down!=-1 && walk[down]!=-1 && visited[down]==0 )
        {
            if(dfsList.indexOf(down)!==-1){
                 dfsList.filter((x)=>{return x!==down})
            }
            dfsList.unshift(down);prev[down]=vertices[currNode]
                };
        
        visited[currNode]=1;
        
            if(delay!=0){
            setTimeout(() => {
                if(currNode==final)
                {   
                    showPath(currNode,findDistance(currNode,0)+1);
                }else{
                currNode==start?0:vertices[currNode].classList.add(classOnStep);  
            }
        }, i*delay); }
        else{
             if(currNode==final)
                {   
                    showPath(currNode,findDistance(currNode,0)+1);
                }else{
                    currNode==start?0:vertices[currNode].classList.add(classOnStep);  
                    }
        }
        if(currNode==final)
            break;

    }

    return i+findDistance(final,0)+1;

}

export default dfs;