#ifndef USER_INFO_H
#define USER_INFO_H
#include<QString>
#include<qsqlquery.h>
#include<qvariant.h>

class user_info
{
public:
    user_info();
    static user_info *ptr_user_infor;
    static user_info *get_instance()
    {
        if(nullptr == ptr_user_infor)
            ptr_user_infor = new user_info;
        return ptr_user_infor;
    }
    void load_info(QString);//通过UID加载数据
    QList<user_info> get_info_to_manage_user(QString );//将搜索信息传给manage_user
    QList<user_info> load_all_user_info();//展示用户信息
    QString out_user_uid();//获取UID
    QString out_user_psd();//获取密码
    QString out_user_name();//获取昵称
    int out_changzhu_cnt_4();//获取常驻4星保底数
    int out_changzhu_cnt_5();//获取常驻5星保底数
    int out_juese_cnt_4();//获取角色4星保底数
    int out_juese_cnt_5();//获取角色5星保底数
    int out_wuqi_cnt_4();//获取武器4星保底数
    int out_wuqi_cnt_5();//获取武器5星保底数
    int out_user_treasure();//获取原石数
    void change_user_treasure(int x);
private:
    QString user_uid;//UID
    QString user_psd;//密码
    QString user_name;//昵称
    int changzhu_cnt_4;//常驻4星保底数
    int changzhu_cnt_5;//常驻5星保底数
    int juese_cnt_4;//角色4星保底数
    int juese_cnt_5;//角色5星保底数
    int wuqi_cnt_4;//武器4星保底数
    int wuqi_cnt_5;//武器5星保底数
    int user_treasure;//原石数
};

#endif // USER_INFO_H
