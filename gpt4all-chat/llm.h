#ifndef LLM_H
#define LLM_H

#include <QObject>

class LLM : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int32_t threadCount READ threadCount WRITE setThreadCount NOTIFY threadCountChanged)
    Q_PROPERTY(bool serverEnabled READ serverEnabled WRITE setServerEnabled NOTIFY serverEnabledChanged)
    Q_PROPERTY(bool compatHardware READ compatHardware NOTIFY compatHardwareChanged)

public:
    static LLM *globalInstance();

    int32_t threadCount() const;
    void setThreadCount(int32_t n_threads);
    bool serverEnabled() const;
    void setServerEnabled(bool enabled);

    bool compatHardware() const { return m_compatHardware; }

    Q_INVOKABLE bool checkForUpdates() const;
    Q_INVOKABLE bool directoryExists(const QString &path) const;
    Q_INVOKABLE bool fileExists(const QString &path) const;
    Q_INVOKABLE qint64 systemTotalRAMInGB() const;
    Q_INVOKABLE QString systemTotalRAMInGBString() const;

Q_SIGNALS:
    void chatListModelChanged();
    void modelListChanged();
    void threadCountChanged();
    void serverEnabledChanged();
    void compatHardwareChanged();

private:
    int32_t m_threadCount;
    bool m_serverEnabled;
    bool m_compatHardware;

private:
    explicit LLM();
    ~LLM() {}
    friend class MyLLM;
};

#endif // LLM_H
