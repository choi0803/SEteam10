// class = SearchUI
// Description = Search의 바운더리 클래스
// Author = 최상혁
class SearchUI {
private:

public:
	void startInterface(Search* search);
	void selectOptions(Search* search);
};

// class = Search
// Description = Search의 컨트롤 클래스
// Author = 최상혁
class Search {
private:

public:
	Search();
	void showAbleCompany();
};

// class = ApplyUI
// Description = Apply의 바운더리 클래스
// Author = 최상혁
class ApplyUI {
private:

public:
	void startInterface(Apply* app);
	void apply(Apply* app);
};

// class = Apply
// Description = Apply의 컨트롤 클래스
// Author = 최상혁
class Apply {
private:
	Recruit* recruit;
public:
	Apply();
	void applyAdd();
};