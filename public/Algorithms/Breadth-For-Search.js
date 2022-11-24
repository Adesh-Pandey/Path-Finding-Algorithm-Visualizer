let prev=[];
let initial=0;



const findDistance=(num,i)=>{

    if(num==initial){
        return ++i;
    }
    i++;
    return findDistance(Number(prev[num].id),i);
}
const BFS=(vertices,start,final,walk,n,m,classOnStep,delay)=>{
    
    initial=start;
    let visited=[];
    for (let i = 0; i < vertices.length; i++) {
        visited[i] = 0;
        prev[i]=0;
    }
    let bfsList=[];
    bfsList.push(start);
    bfsList.push(null);
    let size=n*m;
    
    let i=0;
    const showPath=(index,i)=>{

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

    while(bfsList.length!=0){
        i++;

        let ans=0;
         ans=bfsList.shift();
        if(ans==null){
            bfsList.length!=0?bfsList.push(null):0;
            continue;
        }
        let up= (ans-m)<0?-1:(ans-m);
        let down=(ans+m)>size-1?-1:(ans+m);
        let left=(ans-1)<0?-1:(ans-1);
        let right=(ans+1)>size-1?-1:(ans+1);

        if(up!=-1 && walk[up]!=-1 && visited[up]==0 && bfsList.indexOf(up)==-1)
        {bfsList.push(up);prev[up]=vertices[ans]};
        
        if(left!=-1 && walk[left]!=-1 && (ans)%m!=0  && visited[left]==0 && bfsList.indexOf(left)==-1)
        {bfsList.push(left);prev[left]=vertices[ans]};
        
        if(right!=-1 && walk[right]!=-1 && (ans+1)%m!=0 && visited[right]==0 && bfsList.indexOf(right)==-1)
        {bfsList.push(right);prev[right]=vertices[ans]};

        if(down!=-1 && walk[down]!=-1 && visited[down]==0 && bfsList.indexOf(down)==-1)
        {bfsList.push(down);prev[down]=vertices[ans]};

        visited[ans]=1;
        
            if(delay!=0){
            setTimeout(() => {
                if(ans==final)
                {   
                    
                    showPath(ans,findDistance(ans,0)+1);
                }else{
                ans==start?0:vertices[ans].classList.add(classOnStep);  
            }
        }, i*delay); }
        else{
             if(ans==final)
                {   
                    showPath(ans,findDistance(ans,0)+1);
                }else{
                    ans==start?0:vertices[ans].classList.add(classOnStep);  
                    }
        }
        if(ans==final)
            break;

    }


    return i+findDistance(final,0)+1;

}

export default BFS;