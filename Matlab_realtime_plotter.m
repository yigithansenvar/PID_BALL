

clear all
close all
clc
 


arduino=serial('COM13','BaudRate',9600); % hangi porta baðlý olduðunu yazýyoruz
fopen(arduino); 

CM(1)=0;
time(1)=0;
i=1;
tic;


while (toc<=100)
   
   CM(2)=fscanf(arduino,'%f');
   time(2)=toc;
   figure(1);
   grid on;
   axis([toc-10, toc+10, 0, 35])
   h(i)=plot(time,CM,'b','LineWidth',5);
   hold on
   CM(1)=CM(2);
   time(1)=time(2);
 if(i >= 300)
   delete(h(i-299));
   end
i=i+1;
 
end
 
fclose(arduino);