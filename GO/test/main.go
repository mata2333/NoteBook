package main

import (
	"fmt"
	"io"
	"os"
	"path/filepath"
	"runtime"
	"strings"
)

func copyFile(src, dst string) error {
	sourceFile, err := os.Open(src)
	if err != nil {
		return fmt.Errorf("could not open source file: %w", err)
	}
	defer func(sourceFile *os.File) {
		err := sourceFile.Close()
		if err != nil {
			_ = fmt.Errorf("sourceFile Close failed: %w", err)
		}
	}(sourceFile)

	dstDir := filepath.Dir(dst)
	if err := os.MkdirAll(dstDir, os.ModePerm); err != nil {
		return fmt.Errorf("could not create destination directory: %w", err)
	}

	destinationFile, err := os.Create(dst)
	if err != nil {
		return fmt.Errorf("could not create destination file: %w", err)
	}
	defer func(destinationFile *os.File) {
		err := destinationFile.Close()
		if err != nil {
			_ = fmt.Errorf("destinationFile Close failed: %w", err)
		}
	}(destinationFile)

	if _, err := io.Copy(destinationFile, sourceFile); err != nil {
		return fmt.Errorf("could not copy file: %w", err)
	}
	return nil
}

func main() {
	root := "d:\\"
	maxDepth := 3
	err := filepath.Walk(root, func(path string, info os.FileInfo, err error) error {
		if err != nil {
			if os.IsPermission(err) {
				return filepath.SkipDir
			}
			fmt.Println("Error accessing path", path, ":", err)
			return err
		}
		var separator string
		if runtime.GOOS == "windows" {
			separator = "\\"
		} else {
			separator = "/"
		}
		cleanPath := filepath.Clean(path)
		if info.IsDir() && strings.Count(cleanPath, separator) == maxDepth {
			return filepath.SkipDir
		}
		ext := filepath.Ext(path)
		if ext == ".jpeg" {
			fileSize := info.Size()
			if fileSize < 10*1024 {
				err := copyFile(path, "."+separator+"output"+separator+strings.TrimSuffix(info.Name(), ".jpeg")+".jpg")
				if err != nil {
					return err
				}
			}
		}
		fmt.Println(cleanPath)
		return nil
	})
	if err != nil {
		fmt.Println("Error walking the path:", err)
	}
}
