// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ui/ozone/common/gl_ozone_egl.h"

#include "ui/gl/gl_bindings.h"
#include "ui/gl/gl_context.h"
#include "ui/gl/gl_context_egl.h"
#include "ui/gl/gl_egl_api_implementation.h"
#include "ui/gl/gl_gl_api_implementation.h"
#include "ui/gl/gl_share_group.h"
#include "ui/gl/gl_surface.h"
#include "ui/gl/gl_surface_egl.h"

namespace ui {

bool GLOzoneEGL::InitializeGLOneOffPlatform() {
  if (!gl::GLSurfaceEGL::InitializeOneOff(GetNativeDisplay())) {
    LOG(ERROR) << "GLSurfaceEGL::InitializeOneOff failed.";
    return false;
  }
  return true;
}

bool GLOzoneEGL::InitializeStaticGLBindings(
    gl::GLImplementation implementation) {
  if (!LoadGLES2Bindings())
    return false;

  gl::SetGLImplementation(gl::kGLImplementationEGLGLES2);
  gl::InitializeStaticGLBindingsGL();
  gl::InitializeStaticGLBindingsEGL();

  return true;
}

void GLOzoneEGL::InitializeDebugGLBindings() {
  gl::InitializeDebugGLBindingsGL();
  gl::InitializeDebugGLBindingsEGL();
}

void GLOzoneEGL::ClearGLBindings() {
  gl::GLSurfaceEGL::ResetForTesting();
  gl::ClearGLBindingsGL();
  gl::ClearGLBindingsEGL();
}

bool GLOzoneEGL::GetGLWindowSystemBindingInfo(
    gl::GLWindowSystemBindingInfo* info) {
  return gl::GetGLWindowSystemBindingInfoEGL(info);
}

scoped_refptr<gl::GLContext> GLOzoneEGL::CreateGLContext(
    gl::GLShareGroup* share_group,
    gl::GLSurface* compatible_surface,
    gl::GpuPreference gpu_preference) {
  return gl::InitializeGLContext(new gl::GLContextEGL(share_group),
                                 compatible_surface, gpu_preference);
}

scoped_refptr<gl::GLSurface> GLOzoneEGL::CreateSurfacelessViewGLSurface(
    gfx::AcceleratedWidget window) {
  // This will usually not be implemented by the platform specific version.
  return nullptr;
}

}  // namespace ui
