<img width="1228" height="322" alt="image" src="https://github.com/user-attachments/assets/0c8f4550-5495-4aed-ac6e-e587dd2c7de4" />

```mermaid
classDiagram
    class Document {
        -List~GraphicalObject~ graphicalObjects
        -List~Style~ styles
    }

    class GraphicalObject {
        -String id
        -String name
        -LineStyle lineStyle
        -FillStyle fillStyle
        +draw()
        +move()
        +resize()
    }

    class Point {
        -double x
        -double y
    }

    class Polyline {
        -List~Point~ points
    }

    class Rectangle {
        -double x
        -double y
        -double width
        -double height
    }

    class Ellipse {
        -double centerX
        -double centerY
        -double radiusX
        -double radiusY
    }

    class Polygon {
        -List~Point~ vertices
    }

    class Text {
        -String content
        -String font
        -double fontSize
        -double x
        -double y
    }

    class Style {
        <<abstract>>
        -String id
        -String name
    }

    class LineStyle {
        -LineType lineType
        -double thickness
        -Color color
    }

    class FillStyle {
        -Color color
        -FillPattern pattern
        -String texture
    }

    class LineType {
        <<enumeration>>
        SOLID
        DASHED
        DOTTED
        DASH_DOT
    }

    class FillPattern {
        <<enumeration>>
        NONE
        SOLID
        HATCH
        CROSS_HATCH
        DIAGONAL_HATCH
    }

    class Color {
        -int red
        -int green
        -int blue
        -int alpha
    }

    %% Inheritance relationships
    GraphicalObject <|-- Point
    GraphicalObject <|-- Polyline
    GraphicalObject <|-- Rectangle
    GraphicalObject <|-- Ellipse
    GraphicalObject <|-- Polygon
    GraphicalObject <|-- Text

    Style <|-- LineStyle
    Style <|-- FillStyle

    %% Composition relationships
    Document *-- GraphicalObject
    Document *-- Style
    
    GraphicalObject *-- LineStyle
    GraphicalObject *-- FillStyle
    
    Polyline *-- Point
    Polygon *-- Point
    
    LineStyle --> LineType
    LineStyle --> Color
    FillStyle --> Color
    FillStyle --> FillPattern
```
