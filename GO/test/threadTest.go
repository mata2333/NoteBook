package test

import (
	"fmt"
	"io"
	"os"
	"path/filepath"
	"runtime"
	"strings"
	"sync"
	"time"
)

func copyFile(src, dst string) error {
	dst = dst + strings.TrimSuffix(src, ".jpeg") + ".jpg"
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
		//time.Sleep(1 * time.Millisecond)
		if err != nil {
			return err
		}
		//fmt.Println(src, "done")
	}
	return nil
}

func main() {
	start := time.Now()

	root := ".\\images"
	//dst := ".\\output"
	maxDepth := 10
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
			if fileSize >= 10*1024 {
				jpegFiles = append(jpegFiles, path)
			}
		}
		return nil
	})
	if err != nil {
		fmt.Println("Error walking the path:", err)
	}
	duration := time.Since(start)
	fmt.Println("寻找符合条件的.jpeg文件耗时:", duration)
	fmt.Println(len(jpegFiles))
	start = time.Now()

	var wg sync.WaitGroup
	for _ = range jpegFiles {
		wg.Add(1)

		go func() {
			defer wg.Done()
			time.Sleep(20000 * time.Millisecond)
			//err := copyFile(file, dst+separator)
			//if err != nil {
			//	fmt.Println(err)
			//}
		}()
	}
	wg.Wait()

	duration = time.Since(start)
	fmt.Println("处理文件耗时:", duration)
}
