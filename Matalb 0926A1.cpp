//2017年9月26日20:34:34 
tform=maketform(transform_type,transform_parameters);
transform_type=['affine','box'];


T=[2,0,0;0,3,0;0,0,1];
tform=maketform('affine',T); %用T和affine 方法进行矩阵的变换 
tform.tdata.T; T被存储在了创建的tform-struct里面。同时包括的还有Tinv 
tform.tdata.Tinv
%IPT 两个点变换函数inter-points-tranformation
tformfwd 进行正变换tforminv进行逆变换
XY=tformfwd(WZ,tform)  首先创建tform结构，然后对于tform进行操作。


WZ= [2,3;4,5;,6,7] ;
XY =tformfwd(WZ,tform);
WZ2=tforminv(XY,tform);进行放大变换，之后再变换回来。

T1=[1,0,0;0.2,1,0;0,0,1] ;
tform2=maketform('affine',T1);
figure,vistformfwd(tform2,[0,100],[0,100]);首先创建一个图层，之后画图 
%就是为了 创建一个100*100大小的矩阵，当然，这个像元肯定是可以继续缩小，但是也不一定哦。

T的专业名字叫做 仿射变换矩阵
T=[1,0,0;0.2,1,0;0,0,1] ;
几个仿射变换矩阵的合成依旧是仿射变换矩阵可以用T矩阵的相乘得到。
Tscale=[1.5,0,0;0,2,0;0,0,1] %最后一个是001是仿射变换矩阵的标志
Trotation=[cos(pi/4) sin(pi/4) 0;-sin(pi/4) cos(pi/4) 0;0 0 1] ;
tshear = [1,0,0;0.2,1,0;0,0,1];
T3 =Tscale*Trotation*Tshear;
tform3=maketform('affine',T3);
figure,vistformfwd(tform3,[0,100],[0,100]);
%shear 就是一个水平层次上面的放缩情况，或者说是水平轴的翻转。 


img空间变换 
imtransform 线性等角空间变换，一个缩放一个旋转，一个平移构成。
T=[scos,ssin,0;-ssin,scos,0;x,y,0] ;
g=imtransform(f,tform,interp);  interp 可以用nearest或者bilinear或者bicubic但是一定是字符串形式
 
f=checkerboard(50,2,3); 
s=0.8;
theta=pi/6;

T=[s*cos(theta),s*sin(theta),0;-s*sin(theta),s*cos(theta),0;0,0,1];
tform=maketform('affine',T);
g1=imtransform(f,tform);
g2=imtransform(f,tform,'nearset');%就是变换不单单是一个像素空间关系的问题，更多的是关于像素的灰度变化的问题，也就是你的灰度在
变化了之后会变成一个什么杨的对应关系，也就是寻找共轭像元的灰度值。 
也就是对于个g1这种带有矩阵的操作运算的东西，最后的产品是img，所以要用imshow(img) 来显示。
figure就是创建了一个图层，然后用来显示东西。


FillValue就是用来填充非图像区域之外的像素颜色。

空间分辨率对于光谱变化的影响：
 
 注意矩阵的前向变换和后向变换 。
 
 
 对于地物的光谱的分析是通过改变空间分辨率的，
 也就是一个像元多大，
 而这种像元多大的工作是需要你的进行不断的图像变换的，
 同时一旦涉及到了图像的空间变换就必然要涉及到图像的灰度的拉伸等等。 
 
 注意envi里面是用sample作为横轴，而line作为纵轴的。
 fileinformation应该是读取的一个headers文件的结果。
 
 比较亮的一些物体，或者说反射率比较高的东西。
 然后植被的话，普遍是有一个植物的光谱特征，三个波段。
 高反射的——逐渐下降的趋势，并且可见光区域高反射。 
 道路，在长波波段的DN增加，因为比较灰暗，然后温度比较高。呈现上升趋势。
 
 这个重采样的操作，一个是对于波段的，一个是对于像元的重采样，也就是：basic tool-> resize data
 
 resample和resize的区别是啥？？？？resample应该是用于重新选择大小，而resize应该是用于像元的大小进行改变。 
 
