#include "signalblocker.hpp"

#include <QDebug>

SignalBlockerAttachedType::SignalBlockerAttachedType(QObject* parent)
  : QObject(parent), enabledM{false}, attacheeM{parent}
{
}

SignalBlockerAttachedType::~SignalBlockerAttachedType()
{
    if (attacheeM)
    {
        attacheeM->blockSignals(false);
    }
}

bool SignalBlockerAttachedType::enabled() const
{
    return enabledM;
}

void SignalBlockerAttachedType::setEnabled(bool enabled)
{
    qDebug() << "blocker: " << enabled;
    if (enabled == enabledM)
    {
        return;
    }

    if (attacheeM)
    {
        attacheeM->blockSignals(enabled);
    }

    enabledM = enabled;
    emit enabledChanged();
}
