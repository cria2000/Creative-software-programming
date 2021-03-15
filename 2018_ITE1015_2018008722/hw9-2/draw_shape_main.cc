#include<iostream>
#include<vector>
#include<string>
#include"draw_shape.h"
using namespace std;
int main(){
	vector<Shape *> shapes;
	int cheight, cwidth;
	cin>>cheight>>cwidth;
	Canvas canvas(cheight,cwidth);
	canvas.Print();
	string cmd;
	while(true){
		cin>>cmd;
		if (cmd=="quit") break;
		else if (cmd=="draw"){
			canvas.Clear();
			for(int i=0;i<shapes.size();i++)
				shapes[i]->Draw(&canvas);
			canvas.Print();
		}
		else if (cmd=="dump"){
			for(int i=0;i<shapes.size();i++){
				cout<<i<<" ";
				shapes[i]->printInfo();}
		}
		else if (cmd=="delete"){
			int num;
			cin>>num;
			if(num<shapes.size()){
			       	shapes.erase(shapes.begin()+num);
			}

		}
		else if (cmd=="resize"){
			cin>>cheight>>cwidth;
			canvas.Resize(cheight,cwidth);
			for(int i=0;i<shapes.size();i++)
				shapes[i]->Draw(&canvas);
		}
		else if (cmd=="add"){
			string type;
			int x,y;
			char brush;
			cin>>type>>x>>y;
			if(type=="rect"){
				int height, width;
				cin>>height>>width>>brush;
				shapes.push_back(new Rectangle(x,y,height,width,brush));
				shapes[shapes.size()-1]->Draw(&canvas);
			} else if(type=="tri_up"){
				int height;
				cin>>height>>brush;
				shapes.push_back(new UpTriangle(x,y,height,brush));
				shapes[shapes.size()-1]->Draw(&canvas);
					
			}
			else if(type=="tri_down"){
				int height;
				cin>>height>>brush;
				shapes.push_back(new DownTriangle(x,y,height,brush));
				shapes[shapes.size()-1]->Draw(&canvas);
					
			}
			else if(type=="diamond"){
				int distance;
				cin>>distance>>brush;
				shapes.push_back(new Diamond(x,y,distance,brush));
				shapes[shapes.size()-1]->Draw(&canvas);
			}
		}
	}
	return 0;
	
}
	
