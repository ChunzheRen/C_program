//2017��9��26��20:34:34 
tform=maketform(transform_type,transform_parameters);
transform_type=['affine','box'];


T=[2,0,0;0,3,0;0,0,1];
tform=maketform('affine',T); %��T��affine �������о���ı任 
tform.tdata.T; T���洢���˴�����tform-struct���档ͬʱ�����Ļ���Tinv 
tform.tdata.Tinv
%IPT ������任����inter-points-tranformation
tformfwd �������任tforminv������任
XY=tformfwd(WZ,tform)  ���ȴ���tform�ṹ��Ȼ�����tform���в�����


WZ= [2,3;4,5;,6,7] ;
XY =tformfwd(WZ,tform);
WZ2=tforminv(XY,tform);���зŴ�任��֮���ٱ任������

T1=[1,0,0;0.2,1,0;0,0,1] ;
tform2=maketform('affine',T1);
figure,vistformfwd(tform2,[0,100],[0,100]);���ȴ���һ��ͼ�㣬֮��ͼ 
%����Ϊ�� ����һ��100*100��С�ľ��󣬵�Ȼ�������Ԫ�϶��ǿ��Լ�����С������Ҳ��һ��Ŷ��

T��רҵ���ֽ��� ����任����
T=[1,0,0;0.2,1,0;0,0,1] ;
��������任����ĺϳ������Ƿ���任���������T�������˵õ���
Tscale=[1.5,0,0;0,2,0;0,0,1] %���һ����001�Ƿ���任����ı�־
Trotation=[cos(pi/4) sin(pi/4) 0;-sin(pi/4) cos(pi/4) 0;0 0 1] ;
tshear = [1,0,0;0.2,1,0;0,0,1];
T3 =Tscale*Trotation*Tshear;
tform3=maketform('affine',T3);
figure,vistformfwd(tform3,[0,100],[0,100]);
%shear ����һ��ˮƽ�������ķ������������˵��ˮƽ��ķ�ת�� 


img�ռ�任 
imtransform ���ԵȽǿռ�任��һ������һ����ת��һ��ƽ�ƹ��ɡ�
T=[scos,ssin,0;-ssin,scos,0;x,y,0] ;
g=imtransform(f,tform,interp);  interp ������nearest����bilinear����bicubic����һ�����ַ�����ʽ
 
f=checkerboard(50,2,3); 
s=0.8;
theta=pi/6;

T=[s*cos(theta),s*sin(theta),0;-s*sin(theta),s*cos(theta),0;0,0,1];
tform=maketform('affine',T);
g1=imtransform(f,tform);
g2=imtransform(f,tform,'nearset');%���Ǳ任��������һ�����ؿռ��ϵ�����⣬������ǹ������صĻҶȱ仯�����⣬Ҳ������ĻҶ���
�仯��֮�����һ��ʲô��Ķ�Ӧ��ϵ��Ҳ����Ѱ�ҹ�����Ԫ�ĻҶ�ֵ�� 
Ҳ���Ƕ��ڸ�g1���ִ��о���Ĳ�������Ķ��������Ĳ�Ʒ��img������Ҫ��imshow(img) ����ʾ��
figure���Ǵ�����һ��ͼ�㣬Ȼ��������ʾ������


FillValue������������ͼ������֮���������ɫ��

�ռ�ֱ��ʶ��ڹ��ױ仯��Ӱ�죺
 
 ע������ǰ��任�ͺ���任 ��
 
 
 ���ڵ���Ĺ��׵ķ�����ͨ���ı�ռ�ֱ��ʵģ�
 Ҳ����һ����Ԫ���
 ��������Ԫ���Ĺ�������Ҫ��Ľ��в��ϵ�ͼ��任�ģ�
 ͬʱһ���漰����ͼ��Ŀռ�任�ͱ�ȻҪ�漰��ͼ��ĻҶȵ�����ȵȡ� 
 
 ע��envi��������sample��Ϊ���ᣬ��line��Ϊ����ġ�
 fileinformationӦ���Ƕ�ȡ��һ��headers�ļ��Ľ����
 
 �Ƚ�����һЩ���壬����˵�����ʱȽϸߵĶ�����
 Ȼ��ֲ���Ļ����ձ�����һ��ֲ��Ĺ����������������Ρ�
 �߷���ġ������½������ƣ����ҿɼ�������߷��䡣 
 ��·���ڳ������ε�DN���ӣ���Ϊ�ȽϻҰ���Ȼ���¶ȱȽϸߡ������������ơ�
 
 ����ز����Ĳ�����һ���Ƕ��ڲ��εģ�һ���Ƕ�����Ԫ���ز�����Ҳ���ǣ�basic tool-> resize data
 
 resample��resize��������ɶ��������resampleӦ������������ѡ���С����resizeӦ����������Ԫ�Ĵ�С���иı䡣 
 
