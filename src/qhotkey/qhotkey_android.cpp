#include "qhotkey.h"
#include "qhotkey_p.h"

#include <QGuiApplication>

class QHotkeyPrivateAndroid : public QHotkeyPrivate
{
public:
	// QAbstractNativeEventFilter interface
	bool nativeEventFilter(const QByteArray &eventType, void *message, _NATIVE_EVENT_RESULT *result) override;

protected:
	// QHotkeyPrivate interface
	quint32 nativeKeycode(Qt::Key keycode, bool &ok) Q_DECL_OVERRIDE;
	quint32 nativeModifiers(Qt::KeyboardModifiers modifiers, bool &ok) Q_DECL_OVERRIDE;
	bool registerShortcut(QHotkey::NativeShortcut shortcut) Q_DECL_OVERRIDE;
	bool unregisterShortcut(QHotkey::NativeShortcut shortcut) Q_DECL_OVERRIDE;
};

NATIVE_INSTANCE(QHotkeyPrivateAndroid)

bool QHotkeyPrivate::isPlatformSupported()
{
	// Android platform does not support global hotkeys
	return false;
}

bool QHotkeyPrivateAndroid::nativeEventFilter(const QByteArray &eventType, void *message, _NATIVE_EVENT_RESULT *result)
{
	Q_UNUSED(eventType)
	Q_UNUSED(message)
	Q_UNUSED(result)

	// Empty implementation - no event filtering on Android
	return false;
}

quint32 QHotkeyPrivateAndroid::nativeKeycode(Qt::Key keycode, bool &ok)
{
	Q_UNUSED(keycode)
	
	// Empty implementation - always return 0
	ok = false;
	return 0;
}

quint32 QHotkeyPrivateAndroid::nativeModifiers(Qt::KeyboardModifiers modifiers, bool &ok)
{
	Q_UNUSED(modifiers)
	
	// Empty implementation - always return 0
	ok = false;
	return 0;
}

bool QHotkeyPrivateAndroid::registerShortcut(QHotkey::NativeShortcut shortcut)
{
	Q_UNUSED(shortcut)
	
	// Empty implementation - registration not supported on Android
	error = QStringLiteral("Global hotkeys are not supported on Android");
	return false;
}

bool QHotkeyPrivateAndroid::unregisterShortcut(QHotkey::NativeShortcut shortcut)
{
	Q_UNUSED(shortcut)
	
	// Empty implementation - unregistration not supported on Android
	return false;
}

