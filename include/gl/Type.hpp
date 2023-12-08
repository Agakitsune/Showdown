/*
** EPITECH PROJECT, 2023
** B-YEP-400-RUN-4-1-zappy-raphael.turpin
** File description:
** Type
*/

#pragma once

#include <iostream>

#include "gl/Utils.hpp"

namespace showdown::gl {

    enum class BufferTarget : GLenum {
        ArrayBuffer = GL_ARRAY_BUFFER,
        ElementArrayBuffer = GL_ELEMENT_ARRAY_BUFFER,
        UniformBuffer = GL_UNIFORM_BUFFER,
        ShaderStorageBuffer = GL_SHADER_STORAGE_BUFFER,
        TransformFeedbackBuffer = GL_TRANSFORM_FEEDBACK_BUFFER,
        CopyReadBuffer = GL_COPY_READ_BUFFER,
        CopyWriteBuffer = GL_COPY_WRITE_BUFFER,
        PixelPackBuffer = GL_PIXEL_PACK_BUFFER,
        PixelUnpackBuffer = GL_PIXEL_UNPACK_BUFFER,
        QueryBuffer = GL_QUERY_BUFFER,
        TextureBuffer = GL_TEXTURE_BUFFER,
        AtomicCounterBuffer = GL_ATOMIC_COUNTER_BUFFER,
        DispatchIndirectBuffer = GL_DISPATCH_INDIRECT_BUFFER,
        DrawIndirectBuffer = GL_DRAW_INDIRECT_BUFFER
    };

    enum class BufferUsage : GLenum {
        StreamDraw = GL_STREAM_DRAW,
        StreamRead = GL_STREAM_READ,
        StreamCopy = GL_STREAM_COPY,
        StaticDraw = GL_STATIC_DRAW,
        StaticRead = GL_STATIC_READ,
        StaticCopy = GL_STATIC_COPY,
        DynamicDraw = GL_DYNAMIC_DRAW,
        DynamicRead = GL_DYNAMIC_READ,
        DynamicCopy = GL_DYNAMIC_COPY
    };

    enum class ShaderType : GLenum {
        Vertex = GL_VERTEX_SHADER,
        Fragment = GL_FRAGMENT_SHADER,
        Geometry = GL_GEOMETRY_SHADER,
        Compute = GL_COMPUTE_SHADER,
        TessControl = GL_TESS_CONTROL_SHADER,
        TessEvaluation = GL_TESS_EVALUATION_SHADER
    };

    std::ostream &operator<<(std::ostream &stream, const ShaderType type);

    enum class FramebufferAttach : GLenum {
        Color = GL_COLOR_ATTACHMENT0,
        Depth = GL_DEPTH_ATTACHMENT,
        Stencil = GL_STENCIL_ATTACHMENT,
        DepthStencil = GL_DEPTH_STENCIL_ATTACHMENT
    };

    enum class FramebufferTexture : GLenum {
        Texture2D = GL_TEXTURE_2D,
        Texture2DMultisample = GL_TEXTURE_2D_MULTISAMPLE,
        Texture2DArray = GL_TEXTURE_2D_ARRAY,
        TextureCubeMapPositiveX = GL_TEXTURE_CUBE_MAP_POSITIVE_X,
        TextureCubeMapNegativeX = GL_TEXTURE_CUBE_MAP_NEGATIVE_X,
        TextureCubeMapPositiveY = GL_TEXTURE_CUBE_MAP_POSITIVE_Y,
        TextureCubeMapNegativeY = GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,
        TextureCubeMapPositiveZ = GL_TEXTURE_CUBE_MAP_POSITIVE_Z,
        TextureCubeMapNegativeZ = GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
    };

    enum class DrawBuffer : GLenum {
        None = GL_NONE,
        FrontLeft = GL_FRONT_LEFT,
        FrontRight = GL_FRONT_RIGHT,
        BackLeft = GL_BACK_LEFT,
        BackRight = GL_BACK_RIGHT,
        Color = GL_COLOR_ATTACHMENT0
    };

    enum class DepthFunc : GLenum {
        Never = GL_NEVER,
        Less = GL_LESS,
        Equal = GL_EQUAL,
        LessEqual = GL_LEQUAL,
        Greater = GL_GREATER,
        NotEqual = GL_NOTEQUAL,
        GreaterEqual = GL_GEQUAL,
        Always = GL_ALWAYS
    };

    enum class Capability : GLenum {
        AlphaTest = GL_ALPHA_TEST,
        AutoNormal = GL_AUTO_NORMAL,
        Blend = GL_BLEND,
        // ClipPlane = GL_CLIP_PLANE,
        ColorLogicOp = GL_COLOR_LOGIC_OP,
        ColorMaterial = GL_COLOR_MATERIAL,
        ColorSum = GL_COLOR_SUM,
        ColorTable = GL_COLOR_TABLE,
        Convolution1d = GL_CONVOLUTION_1D,
        Convolution2d = GL_CONVOLUTION_2D,
        CullFace = GL_CULL_FACE,
        DepthTest = GL_DEPTH_TEST,
        Dither = GL_DITHER,
        Fog = GL_FOG,
        Histogram = GL_HISTOGRAM,
        IndexLogicOp = GL_INDEX_LOGIC_OP,
        // Light = GL_LIGHT,
        Lighting = GL_LIGHTING,
        LineSmooth = GL_LINE_SMOOTH,
        LineStipple = GL_LINE_STIPPLE,
        Map1Color4 = GL_MAP1_COLOR_4,
        Map1Index = GL_MAP1_INDEX,
        Map1Normal = GL_MAP1_NORMAL,
        Map1TextureCoord1 = GL_MAP1_TEXTURE_COORD_1,
        Map1TextureCoord2 = GL_MAP1_TEXTURE_COORD_2,
        Map1TextureCoord3 = GL_MAP1_TEXTURE_COORD_3,
        Map1TextureCoord4 = GL_MAP1_TEXTURE_COORD_4,
        Map1Vertex3 = GL_MAP1_VERTEX_3,
        Map1Vertex4 = GL_MAP1_VERTEX_4,
        Map2Color4 = GL_MAP2_COLOR_4,
        Map2Index = GL_MAP2_INDEX,
        Map2Normal = GL_MAP2_NORMAL,
        Map2TextureCoord1 = GL_MAP2_TEXTURE_COORD_1,
        Map2TextureCoord2 = GL_MAP2_TEXTURE_COORD_2,
        Map2TextureCoord3 = GL_MAP2_TEXTURE_COORD_3,
        Map2TextureCoord4 = GL_MAP2_TEXTURE_COORD_4,
        Map2Vertex3 = GL_MAP2_VERTEX_3,
        Map2Vertex4 = GL_MAP2_VERTEX_4,
        Minmax = GL_MINMAX,
        Multisample = GL_MULTISAMPLE,
        Normalize = GL_NORMALIZE,
        PointSmooth = GL_POINT_SMOOTH,
        PointSprite = GL_POINT_SPRITE,
        PolygonOffsetFill = GL_POLYGON_OFFSET_FILL,
        Fill = GL_FILL,
        PolygonOffsetLine = GL_POLYGON_OFFSET_LINE,
        Line = GL_LINE,
        PolygonOffsetPoint = GL_POLYGON_OFFSET_POINT,
        Point = GL_POINT,
        PointSize = GL_POINT_SIZE,
        ProgramPointSize = GL_PROGRAM_POINT_SIZE,
        PolygonSmooth = GL_POLYGON_SMOOTH,
        PolygonStipple = GL_POLYGON_STIPPLE,
        PostColorMatrixColorTable = GL_POST_COLOR_MATRIX_COLOR_TABLE,
        PostConvolutionColorTable = GL_POST_CONVOLUTION_COLOR_TABLE,
        RescaleNormal = GL_RESCALE_NORMAL,
        SampleAlphaToCoverage = GL_SAMPLE_ALPHA_TO_COVERAGE,
        SampleAlphaToOne = GL_SAMPLE_ALPHA_TO_ONE,
        SampleCoverage = GL_SAMPLE_COVERAGE,
        SampleCoverageInvert = GL_SAMPLE_COVERAGE_INVERT,
        True = GL_TRUE,
        Separable2d = GL_SEPARABLE_2D,
        ScissorTest = GL_SCISSOR_TEST,
        StencilTest = GL_STENCIL_TEST,
        Texture1d = GL_TEXTURE_1D,
        Texture2d = GL_TEXTURE_2D,
        Texture3d = GL_TEXTURE_3D,
        TextureCubeMap = GL_TEXTURE_CUBE_MAP,
        TextureGenQ = GL_TEXTURE_GEN_Q,
        TextureGenR = GL_TEXTURE_GEN_R,
        TextureGenS = GL_TEXTURE_GEN_S,
        TextureGenT = GL_TEXTURE_GEN_T,
        VertexProgramPointSize = GL_VERTEX_PROGRAM_POINT_SIZE,
        VertexProgramTwoSide = GL_VERTEX_PROGRAM_TWO_SIDE
    };

    enum class BlendFunc : GLenum {
        Zero = GL_ZERO,
        One = GL_ONE,
        SrcColor = GL_SRC_COLOR,
        OneMinusSrcColor = GL_ONE_MINUS_SRC_COLOR,
        DstColor = GL_DST_COLOR,
        OneMinusDstColor = GL_ONE_MINUS_DST_COLOR,
        SrcAlpha = GL_SRC_ALPHA,
        OneMinusSrcAlpha = GL_ONE_MINUS_SRC_ALPHA,
        DstAlpha = GL_DST_ALPHA,
        OneMinusDstAlpha = GL_ONE_MINUS_DST_ALPHA,
        ConstantColor = GL_CONSTANT_COLOR,
        OneMinusConstantColor = GL_ONE_MINUS_CONSTANT_COLOR,
        ConstantAlpha = GL_CONSTANT_ALPHA,
        OneMinusConstantAlpha = GL_ONE_MINUS_CONSTANT_ALPHA,
        SrcAlphaSaturate = GL_SRC_ALPHA_SATURATE,
        Src1Color = GL_SRC1_COLOR,
        OneMinusSrc1Color = GL_ONE_MINUS_SRC1_COLOR,
        Src1Alpha = GL_SRC1_ALPHA,
        OneMinusSrc1Alpha = GL_ONE_MINUS_SRC1_ALPHA
    };

    enum class BlendEquation : GLenum {
        Add = GL_FUNC_ADD,
        Subtract = GL_FUNC_SUBTRACT,
        ReverseSubtract = GL_FUNC_REVERSE_SUBTRACT,
        Min = GL_MIN,
        Max = GL_MAX
    };

    enum class ClearBuffer : GLenum {
        Color = GL_COLOR,
        Depth = GL_DEPTH,
        Stencil = GL_STENCIL,
        DepthStencil = GL_DEPTH_STENCIL
    };

    enum class CullFace : GLenum {
        Front = GL_FRONT,
        Back = GL_BACK,
        FrontAndBack = GL_FRONT_AND_BACK
    };

    enum class TextureTarget : GLenum {
        Texture1D = GL_TEXTURE_1D,
        Texture2D = GL_TEXTURE_2D,
        Texture3D = GL_TEXTURE_3D,
        Texture1DArray = GL_TEXTURE_1D_ARRAY,
        Texture2DArray = GL_TEXTURE_2D_ARRAY,
        TextureRectangle = GL_TEXTURE_RECTANGLE,
        TextureCubeMap = GL_TEXTURE_CUBE_MAP,
        TextureCubeMapArray = GL_TEXTURE_CUBE_MAP_ARRAY,
        TextureBuffer = GL_TEXTURE_BUFFER,
        Texture2DMultisample = GL_TEXTURE_2D_MULTISAMPLE,
        Texture2DMultisampleArray = GL_TEXTURE_2D_MULTISAMPLE_ARRAY
    };

    enum class TextureFilter : GLenum {
        Nearest = GL_NEAREST,
        Linear = GL_LINEAR,
        NearestMipmapNearest = GL_NEAREST_MIPMAP_NEAREST,
        LinearMipmapNearest = GL_LINEAR_MIPMAP_NEAREST,
        NearestMipmapLinear = GL_NEAREST_MIPMAP_LINEAR,
        LinearMipmapLinear = GL_LINEAR_MIPMAP_LINEAR
    };

    enum class TextureWrap : GLenum {
        Repeat = GL_REPEAT,
        MirroredRepeat = GL_MIRRORED_REPEAT,
        ClampToEdge = GL_CLAMP_TO_EDGE,
        ClampToBorder = GL_CLAMP_TO_BORDER
    };

    enum class TextureParameterName : GLenum {
        DepthStencilTextureMode = GL_DEPTH_STENCIL_TEXTURE_MODE,
        BaseLevel = GL_TEXTURE_BASE_LEVEL,
        CompareFunc = GL_TEXTURE_COMPARE_FUNC,
        CompareMode = GL_TEXTURE_COMPARE_MODE,
        LodBias = GL_TEXTURE_LOD_BIAS,
        MinFilter = GL_TEXTURE_MIN_FILTER,
        MagFilter = GL_TEXTURE_MAG_FILTER,
        MinLod = GL_TEXTURE_MIN_LOD,
        MaxLod = GL_TEXTURE_MAX_LOD,
        MaxLevel = GL_TEXTURE_MAX_LEVEL,
        SwizzleR = GL_TEXTURE_SWIZZLE_R,
        SwizzleG = GL_TEXTURE_SWIZZLE_G,
        SwizzleB = GL_TEXTURE_SWIZZLE_B,
        SwizzleA = GL_TEXTURE_SWIZZLE_A,
        WrapS = GL_TEXTURE_WRAP_S,
        WrapT = GL_TEXTURE_WRAP_T,
        WrapR = GL_TEXTURE_WRAP_R,
        BorderColor = GL_TEXTURE_BORDER_COLOR,
        SwizzleRGBA = GL_TEXTURE_SWIZZLE_RGBA
    };

    enum class TextureFormat : GLenum {
        Red = GL_RED,
        RG = GL_RG,
        RGB = GL_RGB,
        RGBA = GL_RGBA,
        BGRA = GL_BGRA,
        RedInteger = GL_RED_INTEGER,
        RGInteger = GL_RG_INTEGER,
        RGBInteger = GL_RGB_INTEGER,
        RGBAInteger = GL_RGBA_INTEGER,
        BGRInteger = GL_BGR_INTEGER,
        BGRAInteger = GL_BGRA_INTEGER,
        Stencil = GL_STENCIL_INDEX,
        Depth = GL_DEPTH_COMPONENT,
        DepthStencil = GL_DEPTH_STENCIL
    };

    enum class TextureInternalFormat : GLenum {
        Red = GL_RED,
        RG = GL_RG,
        RGB = GL_RGB,
        RGBA = GL_RGBA,
        Depth = GL_DEPTH_COMPONENT,
        DepthStencil = GL_DEPTH_STENCIL,
        // Sized
        R8 = GL_R8,
        R8Snorm = GL_R8_SNORM,
        R16 = GL_R16,
        R16Snorm = GL_R16_SNORM,
        RG8 = GL_RG8,
        RG8Snorm = GL_RG8_SNORM,
        RG16 = GL_RG16,
        RG16Snorm = GL_RG16_SNORM,
        R3G3B2 = GL_R3_G3_B2,
        RGB4 = GL_RGB4,
        RGB5 = GL_RGB5,
        RGB8 = GL_RGB8,
        RGB8Snorm = GL_RGB8_SNORM,
        RGB10 = GL_RGB10,
        RGB12 = GL_RGB12,
        RGB16Snorm = GL_RGB16_SNORM,
        RGBA2 = GL_RGBA2,
        RGBA4 = GL_RGBA4,
        RGB5A1 = GL_RGB5_A1,
        RGBA8 = GL_RGBA8,
        RGBA8Snorm = GL_RGBA8_SNORM,
        RGB10A2 = GL_RGB10_A2,
        RGB10A2ui = GL_RGB10_A2UI,
        RGBA12 = GL_RGBA12,
        RGBA16 = GL_RGBA16,
        SRGB8 = GL_SRGB8,
        SRGB8Alpha8 = GL_SRGB8_ALPHA8,
        R16f = GL_R16F,
        RG16f = GL_RG16F,
        RGB16f = GL_RGB16F,
        RGBA16f = GL_RGBA16F,
        R32f = GL_R32F,
        RG32f = GL_RG32F,
        RGB32f = GL_RGB32F,
        RGBA32f = GL_RGBA32F,
        R11fG11fB10f = GL_R11F_G11F_B10F,
        RGB9E5 = GL_RGB9_E5,
        R8i = GL_R8I,
        R8ui = GL_R8UI,
        R16i = GL_R16I,
        R16ui = GL_R16UI,
        R32i = GL_R32I,
        R32ui = GL_R32UI,
        RG8i = GL_RG8I,
        RG8ui = GL_RG8UI,
        RG16i = GL_RG16I,
        RG16ui = GL_RG16UI,
        RG32i = GL_RG32I,
        RG32ui = GL_RG32UI,
        RGB8i = GL_RGB8I,
        RGB8ui = GL_RGB8UI,
        RGB16i = GL_RGB16I,
        RGB16ui = GL_RGB16UI,
        RGB32i = GL_RGB32I,
        RGB32ui = GL_RGB32UI,
        RGBA8i = GL_RGBA8I,
        RGBA8ui = GL_RGBA8UI,
        RGBA16i = GL_RGBA16I,
        RGBA16ui = GL_RGBA16UI,
        RGBA32i = GL_RGBA32I,
        RGBA32ui = GL_RGBA32UI,
        // Compressed
        CompressedRed = GL_COMPRESSED_RED,
        CompressedRG = GL_COMPRESSED_RG,
        CompressedRGB = GL_COMPRESSED_RGB,
        CompressedRGBA = GL_COMPRESSED_RGBA,
        CompressedSRGB = GL_COMPRESSED_SRGB,
        CompressedSRGBAlpha = GL_COMPRESSED_SRGB_ALPHA,
        CompressedRedRGTC1 = GL_COMPRESSED_RED_RGTC1,
        CompressedSignedRedRGTC1 = GL_COMPRESSED_SIGNED_RED_RGTC1,
        CompressedRG_RGTC2 = GL_COMPRESSED_RG_RGTC2,
        CompressedSignedRG_RGTC2 = GL_COMPRESSED_SIGNED_RG_RGTC2,
        CompressedRGBA_BPTC_UNorm = GL_COMPRESSED_RGBA_BPTC_UNORM,
        CompressedSRGBAlpha_BPTC_UNorm = GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM,
        CompressedRGB_BPTC_SignedFloat = GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT,
        CompressedRGB_BPTC_UnsignedFloat = GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT
    };

    enum class TextureDataType : GLenum {
        UnsignedByte = GL_UNSIGNED_BYTE,
        Byte = GL_BYTE,
        UnsignedShort = GL_UNSIGNED_SHORT,
        Short = GL_SHORT,
        UnsignedInt = GL_UNSIGNED_INT,
        Int = GL_INT,
        HalfFloat = GL_HALF_FLOAT,
        Float = GL_FLOAT,
        UnsignedByte332 = GL_UNSIGNED_BYTE_3_3_2,
        UnsignedByte233Rev = GL_UNSIGNED_BYTE_2_3_3_REV,
        UnsignedShort565 = GL_UNSIGNED_SHORT_5_6_5,
        UnsignedShort565Rev = GL_UNSIGNED_SHORT_5_6_5_REV,
        UnsignedShort4444 = GL_UNSIGNED_SHORT_4_4_4_4,
        UnsignedShort4444Rev = GL_UNSIGNED_SHORT_4_4_4_4_REV,
        UnsignedShort5551 = GL_UNSIGNED_SHORT_5_5_5_1,
        UnsignedShort1555Rev = GL_UNSIGNED_SHORT_1_5_5_5_REV,
        UnsignedInt8888 = GL_UNSIGNED_INT_8_8_8_8,
        UnsignedInt8888Rev = GL_UNSIGNED_INT_8_8_8_8_REV,
        UnsignedInt1010102 = GL_UNSIGNED_INT_10_10_10_2,
        UnsignedInt2101010Rev = GL_UNSIGNED_INT_2_10_10_10_REV
    };

    enum class VertexAttributeType : GLenum {
        Byte = GL_BYTE,
        UnsignedByte = GL_UNSIGNED_BYTE,
        Short = GL_SHORT,
        UnsignedShort = GL_UNSIGNED_SHORT,
        Int = GL_INT,
        UnsignedInt = GL_UNSIGNED_INT,
        HalfFloat = GL_HALF_FLOAT,
        Float = GL_FLOAT,
        Double = GL_DOUBLE,
        Fixed = GL_FIXED,
        Int2101010Rev = GL_INT_2_10_10_10_REV,
        UnsignedInt2101010Rev = GL_UNSIGNED_INT_2_10_10_10_REV,
        UnsignedInt10f11f11fRev = GL_UNSIGNED_INT_10F_11F_11F_REV
    };

    enum class DrawMode : GLenum {
        Points = GL_POINTS,
        LineStrip = GL_LINE_STRIP,
        LineLoop = GL_LINE_LOOP,
        Lines = GL_LINES,
        LineStripAdjacency = GL_LINE_STRIP_ADJACENCY,
        LinesAdjacency = GL_LINES_ADJACENCY,
        TriangleStrip = GL_TRIANGLE_STRIP,
        TriangleFan = GL_TRIANGLE_FAN,
        Triangles = GL_TRIANGLES,
        TriangleStripAdjacency = GL_TRIANGLE_STRIP_ADJACENCY,
        TrianglesAdjacency = GL_TRIANGLES_ADJACENCY,
        Patches = GL_PATCHES
    };

    enum class ClearMask : GLenum {
        Color = GL_COLOR_BUFFER_BIT,
        Depth = GL_DEPTH_BUFFER_BIT,
        Stencil = GL_STENCIL_BUFFER_BIT,
        ColorDepth = GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT,
        DepthStencil = GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT,
        ColorStencil = GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT,
        ColorDepthStencil = GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT
    };

    

}

// template<typename E>
// concept isGlEnum = std::is_enum_v<E> && std::same_as<std::underlying_type_t<E>, GLenum>;

template<typename E>
E operator+(const E &e, const int &i) {
    return static_cast<E>(static_cast<GLenum>(e) + i);
}

// template<typename E>
// concept isGlEnumClass = std::is_enum_v<E> && std::same_as<std::underlying_type_t<E>, GLenum> && std::is_class_v<E>;

template<typename E>
// requires isGlEnum<E>
GLenum glEnum(const E &e) {
    return static_cast<GLenum>(e);
}
