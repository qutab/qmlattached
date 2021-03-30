#pragma once

#include <QObject>
#include <QQmlEngine>


class SignalBlockerAttachedType : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool enabled READ enabled WRITE setEnabled NOTIFY enabledChanged)
    QML_ANONYMOUS

public:
    SignalBlockerAttachedType(QObject* parent = nullptr);
    ~SignalBlockerAttachedType() override;

    bool enabled() const;
    void setEnabled(bool enabled);

signals:
    void enabledChanged();

private:
    bool enabledM;
    QObject* attacheeM;
};

class SignalBlocker : public QObject
{
    Q_OBJECT
    QML_ATTACHED(SignalBlockerAttachedType)
    QML_ELEMENT

public:
    static SignalBlockerAttachedType* qmlAttachedProperties(QObject* object)
    {
        return new SignalBlockerAttachedType(object);
    }
};
