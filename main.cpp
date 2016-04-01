//Ez egy konflict amit fel kell oldani!!:)fdsafd feloldottam :) ffasdf

#include<iostream>
#include<vector>
#include<map>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<list>
#include<string>
#include<sstream>
#include<fstream>

using namespace std;
struct point{
    point(float x, float y){
        this->x=x;
        this->y=y;
    }


    float x,y;
};

//összehasonlításhoz
bool operator ==(const point& lhs, const point& rhs){
	return (lhs.x == rhs.x && lhs.y == rhs.y);
}

class A{
public:
	virtual ~A(){cout<<"Destroying base class A!"<<endl;}
//	virtual void solveTask()=0;
//	virtual void read()=0;
//	virtual void write()=0;
	static bool alreadyInitialized;
	static vector<point> points;


	//Jelenleg attól az esettől eltekintünk, amikor van két egymáson levő pont,
	//ezért az elején átnézzük a pontokat és az azonosakból csak egyet hagyunk meg.
	void removeIdenticalPoints(vector<point>& v){
		for(unsigned int i = 0; i<v.size()-1;++i){
			for(unsigned int j = i+1;j<v.size();j++){
				if(v[i] == v[j]){
					v.erase(v.begin()+j);
					j--;
				}
			}
		}
	}

};


class B: public virtual A{
public:
	~B(){cout<<"Destroying derived class B!"<<endl;}
//	void write(){;}

//	void read(){
//		if(!alreadyInitialized){
//			srand(time(NULL));
//				//tesztadatsor mérete
//				unsigned int testDataSize=1000;
//				//Ezen két szám között generálunk random koordinátákat.
//				float lo = -10;
//				float hi = 10;
//				for(unsigned int i = 0; i<testDataSize;i++){
//					float x = lo + static_cast <float> (rand() /( static_cast <float> (RAND_MAX/(hi-lo))));
//					float y = lo + static_cast <float> (rand() /( static_cast <float> (RAND_MAX/(hi-lo))));
//					points.push_back(point(x,y));
//				}

//			//Manuális tesztadatsor
////			points.push_back(point(0,0));
////			points.push_back(point(0,1));
////			points.push_back(point(0,2));
////			points.push_back(point(0,3));
////			points.push_back(point(0,4));
////			points.push_back(point(1,0));
////			points.push_back(point(1,0));
////			points.push_back(point(1,0));

//			removeIdenticalPoints(points);

//			alreadyInitialized=true;
//		}
//	}

	void solveTask(){
		//háromnál kevesebb pont esetén nincs feladat.
		if(points.size()>2){

			map<point, vector<unsigned>, compare> myMap;
			vector<unsigned> tmp;

			//Lényeg:
			for(unsigned int i=0;i<points.size()-1;i++){
				for(unsigned int j = i+1;j<points.size();j++){
					tmp.push_back(i);
					tmp.push_back(j);
					pair<map<point, vector<unsigned> >::iterator, bool> ret;
					ret = myMap.insert(pair<point, vector<unsigned> >(defineLine(points[i], points[j]), tmp));
					if(ret.second==false){
						ret.first->second.push_back(j);
					}
					tmp.clear();
				}
			}
			cout<<endl<<"Gyors algoritmus:"<<endl;
			map<point, vector<unsigned> >::iterator it;
			int count = 1;
			for(it=myMap.begin();it!=myMap.end();it++){
				if(it->second.size()>2){
					cout<<"Egyenes"<<count<<":"<<endl;
					sort(it->second.begin(), it->second.end());
					cout<<"p = "<<it->first.x<<", q = "<<it->first.y<<endl<<endl;
					unsigned comp = it->second[0];
					for(unsigned int i = 0;i<it->second.size();i++){
						if(i==0) cout<<"("<<points[it->second[i]].x<<", "<<points[it->second[i]].y<<")"<<endl;
						else if(it->second[i] != comp){
							comp=it->second[i];
							cout<<"("<<points[it->second[i]].x<<", "<<points[it->second[i]].y<<")"<<endl;
						}
					}
					cout<<endl<<endl;
					count++;
				}
			}

		}else cout<<"A feladat megoldhatatlan!"<<endl;
	}

private:

	point defineLine(point p1, point p2){
		//p: az egyenes és az origó távolsága.
		//q: egyenes x tengellyel bezárt szöge.
		float p, q;
		float n1 = p1.y-p2.y;
		float n2 = -(p1.x-p2.x);
		p = abs((p1.x*n1+p1.y*n2))/(sqrt(n1*n1+n2*n2));
		if(p1.x==p2.x){
			q=90;
		}else{
			q=atan((p1.y-p2.y)/(p1.x-p2.x))*180/M_PI;
		}
		return point(p,q);
	}

	class compare{
	public:
		bool operator()(const point p1, const point p2){
			if(p1.x == p2.x) return p1.y>p2.y;
			return p1.x>p2.x;
		}
	};
};


class C: public virtual A{
public:

	~C(){cout<<"Destroying derived class C!"<<endl;}
	void write(){;}

//	void read(){
//		if(!alreadyInitialized){
//			srand(time(NULL));
//				//tesztadatsor mérete
//				unsigned int testDataSize=1000;
//				//Ezen két szám között generálunk random koordinátákat.
//				float lo = -10;
//				float hi = 10;
//				for(unsigned int i = 0; i<testDataSize;i++){
//					float x = lo + static_cast <float> (rand() /( static_cast <float> (RAND_MAX/(hi-lo))));
//					float y = lo + static_cast <float> (rand() /( static_cast <float> (RAND_MAX/(hi-lo))));
//					points.push_back(point(x,y));
//				}

//		//Manuális tesztadatsor
////		points.push_back(point(0,0));
////		points.push_back(point(0,1));
////		points.push_back(point(0,2));
////		points.push_back(point(0,3));
////		points.push_back(point(0,4));
////		points.push_back(point(1,0));
////		points.push_back(point(1,0));
////		points.push_back(point(1,0));

//		removeIdenticalPoints(points);

//			alreadyInitialized=true;
//		}
//	}

	void solveTask(){
		//háromnál kevesebb pont esetén nincs feladat.
			if(points.size()>2){

				//Lényeg:
				for(unsigned int i=0;i<points.size()-1;i++){             //Utolsót már nem kell megnézni.
					//Feltöltjük a kiértékelendő pontok listáját.
					createPointsToEvaluate();

					//Először kivesszük azokat a pontokat amiket már kiértékeltünk az aktuális pontra nézve.
					removePointsEvaluated(i);

					//Legalább hárompontos egyenesket keresünk.
					evaluateRemainingPoints(i);


				}
				//Megvan az összes keresett egyenes, kiíratjuk az eredményt.
				cout<<endl<<"Lassu algoritmus:"<<endl;
				if(lines.size()==0){
					cout<<"Egy talalat sincs a megadott ponthalmazban!"<<endl;
				}else{
					for(unsigned int i = 0;i<lines.size();i++){
						cout<<"e"<<i+1<<":"<<endl;
						for(unsigned int j=0;j<lines[i].size();j++){
							 cout<<"("<<points[lines[i][j]].x<<","<<points[lines[i][j]].y<<")"<<endl;
						}
					}
				}


			}else cout<<"A feladat megoldhatatlan!"<<endl;

	}


private:
	//meredekség kiszámításához
	float calculateSlope(const point& p1, const point& p2){
		//Nullával nem osztunk
		if(p1.x - p2.x == 0){
			//Visszatérünk nan-el.
			return nanf("");
		}else return (p1.y - p2.y)/(p1.x - p2.x);
	}

	//Kiértékelendő pontok feltöltése indexekkel
	void createPointsToEvaluate(){
		pointsToEvaluate.clear();
		for(unsigned int i = 0;i<points.size();i++){
			pointsToEvaluate.push_back(i);
		}
	}

	//Eltávolítja azokat a pontokat a pointsToEvaluate listából, amiket már nem szükséges kiértékelni.
	void removePointsEvaluated(unsigned index){
		list<unsigned>::iterator iterator;
		for(iterator = pointsToEvaluate.begin();iterator!=pointsToEvaluate.end();++iterator){
			//Kisebb csak nagyobb indexűvel alkothat pontkettőst, különben már jártunk ott.
			if(*iterator<=index){
				iterator = pointsToEvaluate.erase(iterator);
				--iterator;
			}else{
				for(unsigned int j = 0;j<lines.size();j++){
					bool foundIndex=false, foundPoint=false;
					for(unsigned int k = 0;k<lines[j].size();k++){
						if(lines[j][k]==index) foundIndex=true;
						if(lines[j][k]==*iterator) foundPoint=true;
						//Ha egy egyenesen vannak, akkor azt nem kell kiértékelni.
						if(foundIndex && foundPoint){
							iterator = pointsToEvaluate.erase(iterator);
							--iterator;
							break;
						}
					}
				}
			}
		}
	}

	//A kiválasztott pontkettőssel egy egyenesbe eső pontokat keres.
	void evaluateRemainingPoints(unsigned int index){
		//Ha találunk egy legalább három pontos egyenest, ami még nem volt, akkor azokkal már nem alkotunk pontkettősöket.
		vector<unsigned> pointsOnLine;
		//Találatokat tároló vektor.
		vector<unsigned> v;

		list<unsigned>::iterator iterator;
		for(iterator=pointsToEvaluate.begin();iterator!=pointsToEvaluate.end();++iterator){
			bool evaluatePoint=true;
			for(unsigned int k=0;k<pointsOnLine.size();k++){
				if(*iterator==pointsOnLine[k]){
					evaluatePoint=false;
				}
			}
			if(!evaluatePoint) continue;

			//Eltároljuk a pontkettős meredekségét.
			float m1 = calculateSlope(points[index], points[*iterator]);

			//Kell egy változó, ami tárolja, hogy találtunk -e ponthármast, mert ha nem csak három, hanem
			//több pont is egy egyenesre esik, akkor a legújabb ponthármas egyenesének pontjai közé soroljuk azokat is.
			bool foundThreePoints = false;

			for(unsigned int j = 0;j<points.size();j++){
				//A harmadik pont nem lehet egyik sem a kiválasztott pontkettősből.
				if(j==index || j==*iterator) continue;

				//Egy egyenesre eső három pont feltétele:
				float m2 = calculateSlope(points[index], points[j]);
				if(m1 == m2 || (isnan(m1) && isnan(m2))){
					//találat
					if(!foundThreePoints){
						v.push_back(index);
						v.push_back(*iterator);
						v.push_back(j);
						lines.push_back(v);
						pointsOnLine.push_back(j);
						v.clear();
						foundThreePoints=true;
					}
					else{
						lines[lines.size()-1].push_back(j);
						pointsOnLine.push_back(j);
					}
				}
			}
		}
	}

	//Egy egyenes pontjait tároló vector. Elég, ha az indexeket tároljuk.
	vector<vector<unsigned> > lines;

	//A pontkettősök kiválasztásához szükséges lista. Ez is indexeket tárol.
	//Azért listát használunk, mert sok benne a középről való törlés, amit egy lista jó teljesítménnyel végez.
	list<unsigned> pointsToEvaluate;
};

class CIO : public virtual A{
public:
//	virtual void solveTask()=0;

	void read(){
		stringstream ss;
		unsigned count = 1;
		cout<<"Add meg a pontokat koordinatankent enterrel elvalasztva!"<<endl
			<<"Ha befejezted, nyomd meg a 'q' gombot!"<<endl<<"P"<<count<<":"<<endl
			  <<"x: ";
		float inputX;
		float inputY;
		string input;
		getline(cin, input);
		while(input!="q"){
			ss<<input;
			ss>>inputX;
			ss.clear();
			ss.str(string());
			input="";
			cout<<endl<<"y: ";
			getline(cin, input);
			cout<<"input: "<<input<<endl;
			ss<<input;
			ss>>inputY;
			ss.clear();
			ss.str(string());
			input="";
			point p(inputX, inputY);
			cout<<"p:("<<p.x<<", "<<p.y<<")"<<endl;
			points.push_back(p);
			count++;
			cout<<"P"<<count<<":"<<endl<<"x: ";
			getline(cin, input);
		}
		removeIdenticalPoints(points);
		cout<<"Adatok beolvasva!"<<endl;
	}

	void write(){
		cout<<endl<<"Input pontok:"<<endl;
		for(unsigned i=0; i<points.size();i++){
			cout<<"p"<<i+1<<":"<<"("<<points[i].x<<","<<points[i].y<<")"<<endl;
		}
	}
};


class FIO : public virtual A{
public:
	FIO(string inputFname, string outputFname):inputFname(inputFname), outputFname(outputFname){}

	void read(){
		ifstream input(inputFname.c_str());
		float a,b;
		if(input.is_open()){
			while(input>>a>>b){
				points.push_back(point(a,b));
			}
		}else{
			cout<<"Could not open file: "<<inputFname<<endl;
		}

		input.close();
		removeIdenticalPoints(points);
		cout<<"Adatok beolvasva!"<<endl;
	}

	void write(){
		ofstream of(outputFname.c_str());
		if(of.is_open()){
			for(unsigned i = 0; i<points.size();i++){
				of<<"p"<<i+1<<":"<<"("<<points[i].x<<","<<points[i].y<<")"<<endl;
			}
			cout<<endl<<"Input pontok kiirva fajlba!"<<endl;
		}else{
			cout<<"Could not open file for writing!"<<endl;
		}
		of.close();
	}

//	virtual void solveTask()=0;


private:
	string inputFname, outputFname;
};

class CIOB: public virtual CIO, public virtual B{
public:

//	void solveTask(){
//		B::solveTask();
//	}
//	void read(){
//		CIO::read();
//	}
//	void write(){
//		CIO::write();
//	}

};

class CIOC: public CIO, public C{
public:
//	void solveTask(){
//		C::solveTask();
//	}
//	void read(){
//		CIO::read();
//	}
//	void write(){
//		CIO::write();
//	}

};

class FIOB: public FIO, public B{
public:
	FIOB(string infname, string outfname):FIO(infname, outfname){

	}

//	void solveTask(){
//		B::solveTask();
//	}
//	void read(){
//		FIO::read();
//	}
//	void write(){
//		FIO::write();
//	}

};

class FIOC: public FIO, public C{
public:
	FIOC(string infname, string outfname):FIO(infname, outfname){

	}

//	void solveTask(){
//		C::solveTask();
//	}
//	void read(){
//		FIO::read();
//	}
//	void write(){
//		FIO::write();
//	}
};

bool A::alreadyInitialized=false;
vector<point> A::points;

int main()
{
//	cout<<"Regi algoritmus:"<<endl<<endl;
//	C oldSolver;
//	oldSolver.solveTask();

//	cout<<endl<<"Uj algoritmus:"<<endl<<endl;
//	B newSolver;
//	newSolver.solveTask();


	//1. feladat
	string inFilename="/home/gergely/dev/hf/inputFile";
	string outFilename="/home/gergely/dev/hf/outputFile";
	vector<A*> theCollection;
	for(int i = 0;i<4;i++){
		if(i%2==1){
			theCollection.push_back(new B);
		}else theCollection.push_back(new C);
	}

	FIO fio(inFilename, outFilename);
	fio.read();
	fio.write();


//	theCollection[0]->read();

	for(int i = theCollection.size()-1; i>=0;i--){
		theCollection[i]->solveTask();
		delete theCollection[i];
		theCollection.pop_back();
	}

	//2. feladat
	//Mivel a pont vektor static ezért egy futásnál csak egy variációt lehet kiróbálni.
//	CIOC cioc;
//	CIOB ciob;
//	FIOC fioc(inFilename, outFilename);
//	FIOB fiob(inFilename, outFilename);
//	cout<<"Bemeneti adatok konzolbol, vagy fajlbol(1/2)?"<<endl;
//	string str;
//	int input;
//	getline(cin, str);
//	stringstream ss;
//	ss<<str;
//	ss>>input;
//	ss.clear();
//	ss.str(string());
//	switch(input){
//	case 1:
//		cout<<"Lassu vagy gyors algorimus (1/2)?"<<endl;
//		getline(cin, str);
//		ss<<str;
//		ss>>input;
//		ss.clear();
//		ss.str(string());
//		switch(input){
//		case 1:
//			cioc.read();
//			cioc.write();
//			cioc.solveTask();
//			break;
//		case 2:
//			ciob.read();
//			ciob.write();
//			ciob.solveTask();
//			break;
//		default:
//			cout<<"Rossz input!"<<endl;
//		}

//		break;
//	case 2:

//		cout<<"Lassu vagy gyors algorimus (1/2)?"<<endl;
//		getline(cin, str);
//		ss<<str;
//		ss>>input;
//		ss.clear();
//		ss.str(string());
//		switch(input){
//		case 1:
//			fioc.read();
//			fioc.write();
//			fioc.solveTask();
//			break;
//		case 2:
//			fiob.read();
//			fiob.write();
//			fiob.solveTask();
//			break;
//		default:
//			cout<<"Rossz input!"<<endl;
//		}
//		break;
//	default:
//		cout<<"nem megfelelő input!"<<endl;

//	}


}
