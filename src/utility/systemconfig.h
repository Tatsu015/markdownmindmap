#ifndef SYSTEMCONFIG_H
#define SYSTEMCONFIG_H

#include <QVariant>

#define DefineConfig(name) constexpr const char* name = #name

namespace SystemConfig {
DefineConfig(backgroundColor);
DefineConfig(exportPngTransparent);
DefineConfig(styleSheetPath);
DefineConfig(textColor);
DefineConfig(connectionColor);
DefineConfig(graphicsUpdateDelayTime);
DefineConfig(zoomScrollDirection);
DefineConfig(leftToRightLayoutNodeXSpace);
DefineConfig(leftToRightLayoutNodeYSpace);
DefineConfig(topToBottomLayoutNodeXSpace);
DefineConfig(topToBottomLayoutNodeYSpace);
}

QVariant systemConfig(const QString& name);

void loadSystemConfig(const QString& filePath);
void saveSystemConfig(const QString& filePath);

#endif // SYSTEMCONFIG_H
