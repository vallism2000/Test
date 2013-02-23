// Default empty project template
#ifndef Test_HPP_
#define Test_HPP_

#include <QObject>

#include <bb/cascades/NavigationPane>
#include <bb/cascades/ListView>
#include <bb/cascades/ArrayDataModel>

namespace bb { namespace cascades { class Application; }}

/*!
 * @brief Application pane object
 *
 *Use this object to create and init app UI, to create context objects, to register the new meta types etc.
 */
class Test : public QObject
{
    Q_OBJECT
public:
    Test(bb::cascades::Application *app);
    virtual ~Test() {}
    Q_INVOKABLE void getFullList();
    Q_INVOKABLE void getSearchedList();
private:
    bb::cascades::ListView *list;
    bb::cascades::ArrayDataModel *model1;
    bb::cascades::ArrayDataModel *model2;
};


#endif /* Test_HPP_ */
