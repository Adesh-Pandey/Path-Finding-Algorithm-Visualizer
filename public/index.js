import Dijkstra from "./Algorithms/dijkstra'sAlgo.js"
import BFS from "./Algorithms/Breadth-For-Search.js"

let backgroundSoundDetail=[true,0.07];
let RunningSoundDetail=[true,0.7];
let RestartSoundDetail=[true,0.2];
let SpecialDragDetail=[true,0.5]
let BrickDetail=[true,0.5]
const vol=document.querySelector(".volume");

vol.addEventListener("change",()=>{changeVol()})



const audioTick=document.querySelector(".audioOrNot");

const wallSound=document.querySelector(".down");
wallSound.volume=BrickDetail[1];

const specialDrag=document.querySelector(".up");
specialDrag.volume=SpecialDragDetail[1];


let board=document.querySelector(".board");
let n=15;
let m=35;
let Size=n*m;
let speed;
let classOnStep;
let delay;
let AlgoDoneOnBoard=false;
let MouseCurrentlyIn=-1;
let race=document.querySelector(".race");
race.style.display="none";

let start=((n-(n%2))/2)*m+((m/2)-((m/2)%2))/2;
let final=((n-(n%2))/2)*m+m-((m/2)-((m/2)%2))/2;
let mouseClick=false;
let mouseClickOnSpecial=false;
let movingClass="";
let newDiv;
let isRunning=false;
const backgroundSound=document.querySelector(".background");
const hit=document.querySelector(".hit")
hit.volume=RestartSoundDetail[1];
backgroundSound.volume=backgroundSoundDetail[1];
let run=document.querySelector(".running");

let dots=document.querySelectorAll(".dot");
const load=()=>{
    for (let i = 0; i < dots.length; i++) {
        setTimeout(() => {
            dots[i].style.animation="Blink 0.3s forwards";
        }, i*300);
    }
    setTimeout(() => {
        for (let i = 0; i < dots.length; i++) {
            
                dots[i].style.animation="unBlink 0.3s forwards";
        }
    }, (dots.length)*300);

}

const SoundChanging=document.querySelector("#audiolist");

SoundChanging.addEventListener("change",()=>{
    switch (SoundChanging.value) {
        case "Background":
            audioTick.checked=backgroundSoundDetail[0];
            vol.value=backgroundSoundDetail[1]*100;
            break;
    
        case "Brick":
            audioTick.checked=BrickDetail[0];
            vol.value=BrickDetail[1]*100;
            break;
        case "Running":
            audioTick.checked=RunningSoundDetail[0];
            vol.value=RunningSoundDetail[1]*100;
            break;
        case "Reset":
            audioTick.checked=RestartSoundDetail[0];
            vol.value=RestartSoundDetail[1]*100;
            break;
        case "Special":
            audioTick.checked=SpecialDragDetail[0];
            vol.value=SpecialDragDetail[1]*100;
            break;
        default:
            break;
    }
})

const changeVol=()=>{
    switch (SoundChanging.value) {
        case "Background":
            backgroundSoundDetail[1]=Number(vol.value)/100
            backgroundSound.volume=backgroundSoundDetail[1];
            break;
    
        case "Brick":
            BrickDetail[1]=Number(vol.value)/100;
            wallSound.volume=BrickDetail[1];
            break;
        case "Running":
            RunningSoundDetail[1]=Number(vol.value)/100
            run.volume=RunningSoundDetail[1];
            break;
        case "Reset":
            RestartSoundDetail[1]=Number(vol.value)/100;
            hit.volume=RestartSoundDetail[1]
            break;
        case "Special":
            SpecialDragDetail[1]=Number(vol.value)/100;
            specialDrag.volume=SpecialDragDetail[1];
            break;
        default:
            break;
    }
   
    }
audioTick.addEventListener("change",()=>{
    switch (SoundChanging.value) {
        case "Background":
            backgroundSoundDetail[0]=audioTick.checked;
            !backgroundSoundDetail[0]?backgroundSound.pause():isRunning?"":backgroundSound.play();
            break;
    
        case "Brick":
            BrickDetail[0]=audioTick.checked;
            break;
        case "Running":
            RunningSoundDetail[0]=audioTick.checked;
            !RunningSoundDetail[0]?run.pause():isRunning?run.play():"";
            break;
        case "Reset":
            RestartSoundDetail[0]=audioTick.checked;
            break;
        case "Special":
            SpecialDragDetail[0]=audioTick.checked;
            
            break;
        default:
            break;
    }
})
vol.value=backgroundSoundDetail[1]*100;
run.volume=RunningSoundDetail[1];

for (let index = 0; index < Size; index++) {
    
    newDiv=document.createElement("tb");
    newDiv.setAttribute("id",index);
    newDiv.setAttribute("class","vertices")
    board.appendChild(newDiv);
    
}

let vertices=document.querySelectorAll(".vertices");
let shortFromStart=[];
let prev=[];
let visited=[];
let walk=[];
const clearBoard=()=>{
    for (let i = 0; i < vertices.length; i++) {
                
        vertices[i].classList.remove("instantStep");
        vertices[i].classList.remove(classOnStep);
        vertices[i].classList.remove("path");
        vertices[i].classList.remove("instantPath");


        // ,classOnStep,"path","instantPath"
    }
}
for (let index = 0; index < Size; index++) {

   shortFromStart[index]=Number.MAX_SAFE_INTEGER; 
   visited[index]=0;
    vertices[index].addEventListener("mousedown",(e)=>{
        MouseCurrentlyIn=Number(e.target.id);
        mouseDownForWall(e)});
   prev[index]=0;
   walk[index]=1;


    vertices[index].addEventListener("mouseleave",(drag)=>{
        if(mouseClickOnSpecial  ){
            drag.target.classList.remove(movingClass);
           }
    })

   vertices[index].addEventListener("mouseenter",(drag)=>{
       if(Number(drag.target.id)==MouseCurrentlyIn)
       return;


    MouseCurrentlyIn=Number(drag.target.id);


    let classRestriction=!drag.target.classList.contains("path") 
    &&!drag.target.classList.contains("instantPath") &&
     !drag.target.classList.contains(movingClass) &&
       !drag.target.classList.contains("FastStep")&&
       !drag.target.classList.contains("instantStep")&&
       !drag.target.classList.contains("SlowStep") &&
        !drag.target.classList.contains("MediumStep");
    if( !isRunning&& mouseClick && classRestriction && !mouseClickOnSpecial&& Number(drag.target.id)!=start  && Number(drag.target.id)!=final){

    if(!drag.target.classList.contains("block")){
        walk[index]=-1;
        BrickDetail[0]? wallSound.play():"";
        drag.target.classList.add("block");
    }else{
        walk[index]=1;
        drag.target.classList.remove("block")
    }}

    if(mouseClickOnSpecial && !drag.target.classList.contains("start") && !drag.target.classList.contains("final") && walk[index]!=-1){

        if(movingClass=="start"){
            shortFromStart[start]=Number.MAX_SAFE_INTEGER;
            

            start=Number(drag.target.id);
            shortFromStart[start]=0;
            

        }else{
            final=Number(drag.target.id);
           
        }
        drag.target.classList.add(movingClass);
        if(AlgoDoneOnBoard ){
            clearBoard();
            delay=0;

            switch (document.querySelector("#Algorithms").value) {
                case "BFS":
                    BFS(vertices,start,final,walk,n,m,"instantStep",delay);
                    break;
                case "Dijkstra":
                    Dijkstra(vertices,start,final,walk,n,m,"instantStep",delay);
                    break;
                default:
                    break;
            }

        }
    }
}
);


}

// static starting
vertices[start].classList.add("start");

// if(confirm("Allow us to play audio! ")){
//     backgroundSound.play();
// }


vertices[final].classList.add("final");


document.addEventListener("mouseup",()=>{

    if(mouseClickOnSpecial && SpecialDragDetail[0]){
        specialDrag.play();
        setTimeout(() => {
            specialDrag.pause();
            specialDrag.currentTime=0;
        }, 1200);
    }
    mouseClick=false;
    mouseClickOnSpecial=false;
    movingClass="";
    vertices[start].classList.add("start")
    vertices[final].classList.add("final")
})
const mouseDownForWall=(event)=>{
    mouseClick=true;

    if((Number(event.target.id)==start || Number(event.target.id)==final)&& !isRunning){
        mouseClickOnSpecial=true;
        movingClass=Number(event.target.id)==start?"start":"final";
    }
    
}

const reset=()=>{
    // static starting
    
   

    AlgoDoneOnBoard=false;
    start=((n-(n%2))/2)*m+((m/2)-((m/2)%2))/2;
    final=((n-(n%2))/2)*m+m-((m/2)-((m/2)%2))/2;
    mouseClick=false;
    mouseClickOnSpecial=false;
    movingClass=""

    for (let index = 0; index < Size; index++) {

        shortFromStart[index]=Number.MAX_SAFE_INTEGER; 
        visited[index]=0;
        index!=start|| index!=final ?vertices[index].addEventListener("mousedown",(e)=>{mouseDownForWall(e)}):0;
        prev[index]=0;
        walk[index]=1;
        vertices[index].classList.remove("block","path",classOnStep,"instantStep","instantPath","start","final");
     }
     vertices[start].classList.add("start");


     vertices[final].classList.add("final");
      

    shortFromStart[start]=0;
}


const buttons=document.querySelectorAll(".action");
buttons[0].addEventListener("click",()=>{

    backgroundSound.pause();
    race.style.display="flex";
    
    load();
    let time=setInterval(() => {
        load();
    }, 1200);
    run.currentTime=10;
    if(RunningSoundDetail[0]){
        run.play();
        // run.loop=true;
    }else{
        run.pause();
    }

    buttons[0].disabled=true;
    buttons[0].classList.add("disabled");
    
    buttons[1].disabled=true;
    buttons[1].classList.add("disabled")

    speed=document.querySelector("#Speed").value;
    
    if(speed=="Slow"){
        classOnStep="SlowStep";
        delay=250;
    }else if(speed=="Medium"){
        classOnStep="MediumStep";
        delay=110;
    }else{
        classOnStep="FastStep";
        delay=20;
    }

    if(AlgoDoneOnBoard){
        for (let i = 0; i < vertices.length; i++) {
                
            vertices[i].classList.remove("instantStep");
            vertices[i].classList.remove("FastStep");
            vertices[i].classList.remove("path");
            vertices[i].classList.remove("instantPath");
            
            vertices[i].classList.remove("MediumStep");
            
            vertices[i].classList.remove("SlowStep");


            // ,classOnStep,"path","instantPath"
        }
        
    }

    switch (document.querySelector("#Algorithms").value) {
        case "BFS":
            isRunning=true;
            let BFSenable=BFS(vertices,start,final,walk,n,m,classOnStep,delay);
            
            setTimeout(() => {
                isRunning=false;
                buttons[0].disabled=false;
                buttons[0].classList.remove("disabled")
                run.currentTime=300;
                
                buttons[1].disabled=false;
                buttons[1].classList.remove("disabled")
                race.style.display="none"
            clearInterval(time);
            }, BFSenable*delay);
            setTimeout(() => {
                run.pause();
                backgroundSoundDetail[0]? backgroundSound.play():"";
            }, BFSenable*delay+2000);
            AlgoDoneOnBoard=true;
            for (let i = 0; i < dots.length; i++) {
                dots[i].style.animation="";
                dots[i].style.backgroundColor="white"
            }
            break;
        case "Dijkstra":
            isRunning=true;
            let enable=Dijkstra(vertices,start,final,walk,n,m,classOnStep,delay);
            setTimeout(() => {
                isRunning=false;
                buttons[0].disabled=false;
                buttons[0].classList.remove("disabled")
                run.currentTime=300;
                
                buttons[1].disabled=false;
                buttons[1].classList.remove("disabled")
                race.style.display="none"
            clearInterval(time);
            }, enable*delay);
            setTimeout(() => {
                run.pause();
                backgroundSoundDetail[0]? backgroundSound.play():"";
            }, enable*delay+2000);
            AlgoDoneOnBoard=true;
            for (let i = 0; i < dots.length; i++) {
                dots[i].style.animation="";
                dots[i].style.backgroundColor="white";
            }
            break;
        default:
            break;
    }

});
buttons[1].addEventListener("click",()=>{RestartSoundDetail[0]? hit.play():0;reset()});


