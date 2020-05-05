class Render{
	public:
		int height;	//界面高 
		int width;	//界面宽 
		int size;	//界面大小 
		int color;	// 界面颜色 
		char map[100][100];	//界面信息 
		
	public:
		void Paint();	//绘制界面 
		void Update();	//更新界面 
		void Score();	//显示得分
		
};
