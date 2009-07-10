#ifndef QUSMARTSETTING_H
#define QUSMARTSETTING_H

#include <QObject>
#include <QWidget>
#include <QVariant>
#include <QString>

class QToolButton;

class QUSmartSetting: public QObject {
	Q_OBJECT

public:
	QUSmartSetting(const QString &registryKey);

	virtual QWidget* editor() const = 0;

	virtual void resetToDefaults() = 0;
	virtual bool hasChanges() const = 0;

public slots:
	void reset();

signals:
	void changed();

protected:
	void setValue(const QVariant &value);
	QVariant value(const QVariant &defaultValue) const;
	QToolButton* createResetButton();

private:
	QString _registryKey;
};

#endif // QUSMARTSETTING_H
