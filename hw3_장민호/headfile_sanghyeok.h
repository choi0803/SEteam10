// class = SearchUI
// Description = Search�� �ٿ���� Ŭ����
// Author = �ֻ���
class SearchUI {
private:

public:
	void startInterface(Search* search);
	void selectOptions(Search* search);
};

// class = Search
// Description = Search�� ��Ʈ�� Ŭ����
// Author = �ֻ���
class Search {
private:

public:
	Search();
	void showAbleCompany();
};

// class = ApplyUI
// Description = Apply�� �ٿ���� Ŭ����
// Author = �ֻ���
class ApplyUI {
private:

public:
	void startInterface(Apply* app);
	void apply(Apply* app);
};

// class = Apply
// Description = Apply�� ��Ʈ�� Ŭ����
// Author = �ֻ���
class Apply {
private:
	Recruit* recruit;
public:
	Apply();
	void applyAdd();
};