#ifndef QUPLUGIN_H
#define QUPLUGIN_H

#include <QString>
#include <QMap>

class QTranslator;

class QUPlugin {
public:
	// for compatibility reasons
	virtual int pluginApiVersion() const = 0;
	virtual int songApiVersion() const = 0;

	// general plugin information
	virtual QString name() const = 0;
	virtual QString version() const = 0;
	virtual QString author() const = 0;
	virtual QString description() const = 0;

	// multi-language support: language -> translation (see QLocale)
	virtual QMap<QString, QTranslator*> translations() const = 0;
};

#endif // QUPLUGIN_H