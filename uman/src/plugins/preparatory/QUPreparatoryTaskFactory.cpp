#include "QUPreparatoryTaskFactory.h"
#include "QUPreparatoryTask.h"

#include <QDir>
#include <QLocale>
#include <QCoreApplication>

QUPreparatoryTaskFactory::QUPreparatoryTaskFactory(QObject *parent): QUSimpleTaskFactory(parent) {}

QString QUPreparatoryTaskFactory::name() const {
	return tr("Preparatory Tasks");
}

QUTask* QUPreparatoryTaskFactory::createTask(int type) {
	return new QUPreparatoryTask((QU::PreparatoryTaskModes)type);
}

QList<int> QUPreparatoryTaskFactory::types() const {
	QList<int> result;
	result << QU::autoAssignFiles;
	result << QU::removeUnsupportedTags;
	result << QU::fixAudioLength;
	result << QU::roundGap;
	return result;
}

QMap<QString, QString> QUPreparatoryTaskFactory::translationLocations() const {
	QDir dir = QCoreApplication::applicationDirPath();
	QMap<QString, QString> locations;

	if(dir.cd("plugins") && dir.cd("languages")) {
		locations.insert(QLocale(QLocale::German, QLocale::Germany).name(), dir.filePath("preparatory.de.qm"));
		locations.insert(QLocale(QLocale::Polish, QLocale::Poland).name(), dir.filePath("preparatory.pl.qm"));
	}

	return locations;
}

Q_EXPORT_PLUGIN2(qupreparatorytaskfactory, QUPreparatoryTaskFactory);
