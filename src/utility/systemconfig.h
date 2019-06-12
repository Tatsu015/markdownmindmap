#ifndef SYSTEMCONFIG_H
#define SYSTEMCONFIG_H

#include <QVariant>

namespace SystemConfig {
#define DefineConfig(name) constexpr const char* name = #name

DefineConfig(backgroundColor);
DefineConfig(exportPngTransparent);
DefineConfig(styleSheetPath);
DefineConfig(textColor);
DefineConfig(connectionColor);
DefineConfig(graphicsUpdateDelayTime);
DefineConfig(zoomScrollDirection);
DefineConfig(defaultViewSplitRate);
DefineConfig(leftToRightTreeLayoutNodeXSpace);
DefineConfig(leftToRightTreeLayoutNodeYSpace);
DefineConfig(topToBottomTreeLayoutNodeXSpace);
DefineConfig(topToBottomTreeLayoutNodeYSpace);
DefineConfig(bothSidesTreeLayoutNodeXSpace);
DefineConfig(bothSidesTreeLayoutNodeYSpace);
}

QVariant systemConfig(const QString& name);

void loadSystemConfig(const QString& filePath);
void saveSystemConfig(const QString& filePath);

#endif // SYSTEMCONFIG_H
