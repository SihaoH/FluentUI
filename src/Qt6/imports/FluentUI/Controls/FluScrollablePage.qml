import QtQuick
import QtQuick.Layouts
import QtQuick.Window
import QtQuick.Controls
import FluentUI

FluPage {
    id: control
    property bool autoResetScroll: false
    property alias boundsBehavior: flickable.boundsBehavior
    default property alias content: container.data

    Flickable{
        id: flickable
        clip: true
        anchors.fill: parent
        ScrollIndicator.vertical: FluScrollIndicator {}
        boundsBehavior: Flickable.DragAndOvershootBounds
        contentHeight: container.height
        ColumnLayout {
            id: container
            width: parent.width
            spacing: control.spacing
        }
    }

    function resetScroll() {
        flickable.contentY = 0;
    }

    StackView.onActivated: {
        if (autoResetScroll) {
            resetScroll(); // Call this function to reset the scroll position to the top
        }
    }
}
