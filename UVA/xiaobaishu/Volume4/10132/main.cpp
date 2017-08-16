#include<string.h>
#include<stdio.h>
#include<algorithm>

const int MAXLEN = 1220;
const int MAXFILE = 310;
struct FileFragment
{
	char str[MAXLEN];
	int len;
	int num;
	bool operator < (const FileFragment a) const
	{
		return len < a.len ? true: num < a.num;
	}

};
FileFragment fragment[MAXFILE];
struct FragmentLenList
{
	FragmentLenList()
	{
		next = -1;
		local = -1;
	}
	int next;
        int local;	
}cnt_list[MAXFILE];
int list_cnt;
short status[MAXLEN][3];
FragmentLenList list_fragment[MAXLEN];
inline int min(int a, int b)
{
	return a>b?b:a;
}
void ClearStatus(int file_len)
{
	for(int i = 0; i <= file_len; ++ i)
		for(int j = 0; j < 3; ++ j)
			status[i][j] = 0;
}
void ClearList(int fragment_num, int file_len)
{
	for(int i = 0; i <= file_len; ++ i)
	{
		list_fragment[i].next = -1, list_fragment[i].local = -1;
	}
	ClearStatus(file_len);
	list_cnt = 0;
	
}
void AddToList(FragmentLenList &target, FragmentLenList &temp )
{
	temp.next = target.next;
	target.next = list_cnt ++; 
}
bool CheckCanFront(const char* dst, int dst_len, const char* tmp, int tmp_len)
{
	if(dst_len < tmp_len)
		return false;
	for(int i = 0; i < tmp_len; ++i)
		if(dst[i] != tmp[i])
			return false;
	return true;
}
bool CheckCanTail(const char* dst, int dst_len, const char* tmp, int tmp_len)
{
	if(dst_len < tmp_len)
		return false;
	for(int i = 0; i < tmp_len; ++i)
		if(dst[i + dst_len - tmp_len] != tmp[i])
			return false;
	return true;
}
void GetStatus(const char *target, int len, FileFragment& frag) 
{
	int sta = 0;
	if(CheckCanFront(target, len, frag.str, frag.len))
		sta|=1;
	if(CheckCanTail(target, len, frag.str, frag.len))
		sta|=2;
	if(status != 0)
		++ status[frag.len][sta - 1];
}
bool Check(const char *target, int fragment_num, int file_len)
{
	ClearStatus(file_len);
	for(int i = 0; i < fragment_num; ++ i)
	{
		GetStatus(target, file_len, fragment[i]);
	}
	for(int i = 1; i <= file_len/2; ++i)
	{
		int a1 = status[i][0], a2 = status[i][1], a3 = status[i][2];
		int b1 = status[file_len - i][0], b2 = status[file_len - i][1], b3 = status[file_len -i][2];
		int min_v;
		min_v = min(a1, b2);
		a1 -= min_v;
		b2 -= min_v;
		min_v = min(b1, a2);
		a2 -= min_v;
		b1 -= min_v;
		
		a3 -= b1 + b2;
		b3 -= a1 + a2;
		if(a3 < 0 || a3 != b3)
			return false;
	}
	return true;
}


void Solve(int fragment_num, int file_len)
{
	static char target_str[MAXLEN];
	for(int i = fragment_num - 1; i > 0; --i)
	{
		strcpy(target_str, fragment[0].str);
		strcpy(target_str + fragment[0].len, fragment[i].str);
		if(fragment[0].len + fragment[i].len != file_len) 
			break;
		if(Check(target_str, fragment_num, file_len))
		{
			printf("%s\n", target_str);
			return ;
		}
		
		strcpy(target_str, fragment[i].str);
		strcpy(target_str + fragment[i].len, fragment[0].str);
		if(Check(target_str, fragment_num, file_len))
		{
			printf("%s\n", target_str);
			return ;
		}
	}
}
int main()
{
	int cas;
	scanf("%d", &cas);
	getchar(); getchar();
	for(int cc = 1; cc <= cas; ++ cc)
	{
        	int fragment_num = 0;
	   	while(gets(fragment[fragment_num].str))
		{
			int len = strlen(fragment[fragment_num].str);
			if(len == 0)
				break;
			fragment[fragment_num].len = len;
			fragment[fragment_num].num = fragment_num;
			++ fragment_num;
		}
		std::sort(fragment, fragment + fragment_num);
		int file_len = fragment[0].len + fragment[fragment_num - 1].len;
		Solve(fragment_num, file_len);
		if(cc != cas)
			puts("");
	}
}
