class Block{ 
	public:
		int shape;	//形状 
		int color;	//颜色 
		int speed;	//速度 
		char locate[10][10];	//位置 
		int score;	//得分 
		
	public:
		void Creat();	//构造
		void Random();	//随机出现 
		void Down();	//基础速度自动下落 
		bool IsAgain();	//边界判定及重合判定 
		void Move();	//移动 
		void Rotate();	//旋转
		void Accelerate();	//加速移动 
		bool Judge();	//层满判定 
		void Eliminate();	//消行
		void Add();	//增行 
		bool CheckWin//胜负判定 
		
};
