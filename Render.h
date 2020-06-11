/*	渲染类主要负责	绘制启动、运行、结束界面	*/

#pragma once

class Render {
private:
	Game game;

public:
	void Welcome();		//	启动界面
	void Run();			//	运行界面
	void Over();		//	结束界面

};