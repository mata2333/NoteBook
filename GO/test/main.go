package main

import (
	"fmt"
	"io"
	"os"
	"path/filepath"
	"runtime"
	"strings"
	"sync"
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

func batchCopyFiles(srcs []string, dst string) error {
	for _, src := range srcs {
		fileName := filepath.Base(src)
		err := copyFile(src, dst+strings.TrimSuffix(fileName, ".jpeg")+".jpg")
		if err != nil {
			return err
		}
		fmt.Println(src, "done")
	}
	return nil
}

func main() {
	root := "d:\\"
	dst := ".\\output"
	maxDepth := 3
	var jpegFiles []string
	var separator string

	if runtime.GOOS == "windows" {
		separator = "\\"
	} else {
		separator = "/"
	}
	err := filepath.Walk(root, func(path string, info os.FileInfo, err error) error {
		if err != nil {
			if os.IsPermission(err) {
				return filepath.SkipDir
			}
			fmt.Println("Error accessing path", path, ":", err)
			return err
		}
		cleanPath := filepath.Clean(path)
		if info.IsDir() && strings.Count(cleanPath, separator) == maxDepth {
			return filepath.SkipDir
		}
		ext := filepath.Ext(path)
		if ext == ".jpeg" {
			fileSize := info.Size()
			if fileSize < 10*1024 {
				jpegFiles = append(jpegFiles, path)
				//err := copyFile(path, "."+separator+"output"+separator+strings.TrimSuffix(info.Name(), ".jpeg")+".jpg")
				//if err != nil {
				//	return err
				//}
			}
		}
		//fmt.Println(cleanPath)
		return nil
	})
	if err != nil {
		fmt.Println("Error walking the path:", err)
	}
	fmt.Println(jpegFiles)
	if len(jpegFiles) > 0 {
		var wg sync.WaitGroup
		wg.Add(2)
		go func() {
			defer wg.Done()
			err := batchCopyFiles(jpegFiles[:len(jpegFiles)/2], dst+separator)
			if err != nil {
				fmt.Println(err)
			}
		}()
		go func() {
			defer wg.Done()
			err := batchCopyFiles(jpegFiles[len(jpegFiles)/2:], dst+separator)
			if err != nil {
				fmt.Println(err)
			}
		}()
		wg.Wait()
	} else {
		fmt.Println("Error: no jpegFiles")
	}
}
