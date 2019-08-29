#ifndef SYSTEMCONFIG_H
#define SYSTEMCONFIG_H

#include <QVariant>

namespace SystemConfig {
/** @def
 * This macro is for config definition which loaded from system.conf file.
 * when you want to add definition, use this macro, and add to position ADD HERE TO DEFINECONFIG.
 * ex. when add xxx macro
 * DefineConfig(xxx);
 * This macro expand to " const char* xxx = "xxx" "
 */
#define DefineConfig(name) constexpr const char* name = #name

DefineConfig(backgroundColor);
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
// ADD HERE TO DEFINECONFIG
}

QVariant systemConfig(const QString& name);

void loadSystemConfig(const QString& filePath);
void saveSystemConfig(const QString& filePath);

#endif // SYSTEMCONFIG_H
